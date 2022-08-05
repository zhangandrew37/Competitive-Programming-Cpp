## Exception Safety

### **Basic guarantee:** 
If an exception occurs, the program will be in some **valid, unspecified state**
   - nothing leaked
   - class invariants maintained

Using RAII:
```cpp
void f(){
    MyClass mc;
    auto p = std::make_unique<MyClass>();
    g();
}

```
p is stack-allocated smart pointer
- p's destructor will be called automatically as part of stack unwinding (whether f ended normally or due to exception)
- p's destructor also frees dynamically allocated memory for MyClass object

### **Strong guarantee:** 
If function f throws or propotes exception, the state of the program will be as if **f had not been called**
   - any modification in the program state made by f needs to be undone

i.e.

```cpp
 void f() {
    a.g(); // may throw (provides strong guarantee)
    b.h(); // may throw (provides strong guarantee)
 }
};
```

1. if a.g() throws, nothing has happened
2. if b.h() throws, the effects of a.g() must be undone
  - very hard to do if a.g() has non-local side-effects => not exception-safe (does not offer strong guarantee)

### Solution:

Let's try copy-swap to make f() have a strong guarantee:
```cpp
void C::f() {
    A tempa = a;
    B tempb = b;
    tempa.g();
    tempb.h();
    a = tempa;
    b = tempb;
};
```
  - when assigning ```a = atemp```, it's possible that copy assignment throws

Fix: Pimpl idiom

```cpp
struct CImpl {
    A a;
    B b;
}

class C {
    unique_ptr<CImpl> pImpl;
    public:
        void f() {
            // copy constructor ; making temp copy, passes dereferenced *pImpl
            auto temp = make_unique<CImpl> (*pImpl); 
            temp->a.h();
            temp->b.h();
            std::swap(pImpl, temp); // No-throw (just swaps memory addresses)
        }
}
```

Note: generally, a method can only offer a strong guarantee if all methods it calls offer a strong/no-throw guarantee

### **No throw guarantee**: 
Never throw or propogate exception

- any function will be potentially throwing unless you declare
```cpp
void f() noexcept;
```
- const never throws
```cpp
void f() const noexcept;
```

### STL vectors && Exception Safety
 - STL vectors encapsulate a heap-allocated array
   - follow RAII: when a stack-allocated vector goes out of scope, the internal heap=allocated array is freed

However, consider:
```cpp
void g() {
 vector<MyClass*> v;
}
```
- pointers don't have dsetructors, so only the array is freed

Solution 1:
```cpp
for (auto &x : v) delete x;
```
Solution 2: 
- use smart pointer (i.e. unique_ptrs have destructors, ran by vector's destructor when v goes out of scope)

Consider **vector::emplace_back** (strong guarantee)

If array full:

**Inefficient method:**
- allocates new, larger array
- calls **copy constructor** to copy objects over
  - if copy constructor throws (strong guarantee):
    - destroy new array
    - old array still intact
- delete old array (and replace)

**Move constructor method**

- allocate new, larger array
- call **move constructor** to move objects over
- delete old array (and replace)

However, we need to make move constructor no-throw
- if it throws, old array would no longer be intact 

```cpp
class MyClass {
 public:
 MyClass (MyClass &&other) noexcept { . . . }
 MyClass &operator=(MyClass &&other) noexcept { . . . }
 . . .
};
```