## Exceptions
- main function can't detect error due to encapsulation
- NEVER let destructor throw an exception

We write **handlers** to **catch** exceptions

```cpp
throw InvalidGrade{};
```

try-catch block

```cpp
try {
    ...
} catch (InvalidGrade){
    ...
}

```
- if exception is raised while executing any statement within try, the execution moves to catch block
- after that, program execution ocntinues on next line after catch block
- if any other exception raised (not inside catch, program quits)

can pass information ("fields") to exception object
```cpp
throw InvalidGrade{grade}
```
- recall, InvalidGrade is our object class and grade is an int
- similar to calling constructor
```cpp
try{
    ...
} catch (InvalidGrade ex){
    cout << "Invalid grade: " << ex.getGrade() << endl;
}
```
- catch thrown object into variable ex

## Call chain

```cpp
void f() {
 throw out_of_range{"f"};
}
void g() {
 f();
}
void h() {
 g();
}
int main() {
 try {
 h();
 }
 catch (out_of_range) {
 cerr << "Range error in main()" << endl;
 }
}
```

Main calls h
- h calls g
  - g calls f
    - f raises out_of_range
- Stack unwinding: control goes back through call chain until a handler is found
  1. exception raised in f || o exception handler => execution interrupted and control goes back to g
  2. ...
  3. main has exception handler => exception caught, catch block executed

### Partial exception handling

- handler can catch one error then throw some other error
```cpp
try { . . . }
catch (SomeErrorType s) {
 . . .
 throw SomeOtherError{ . . . };
}
```
- or throw same exception
```cpp
try { . . . }
catch (SomeErrorType s) {
 . . .
 throw;
}
```

- useful for cleanup first
- ex. dynamic memory allocation freed before rethrowing exception (avoid memory leak)

### Catching all exceptions

```cpp
try {
 // do something
} catch (CustomException e) {
 // handle custom error
} catch (out_of_range r) {
 // handle out of range error
} catch (...) { // literally mean ... here
 // handle any other exception type
}
```

### Catching exceptions with subclasses and by reference

```cpp
class E1 {};
class E2: public E1 {};
try {
 // do something
} catch (E1) {
 // will handle exceptions of type E1 or E2
}
```

- Summary: if E2 is a subclass of E1, then catching E1 handles E1 and E2

example: 
```cpp
class E1 {};
class E2: public E1 {};
int main() {
 try {
 cout << "First block: ";
 throw E2{};
 } catch (E2) {
 // This block will run because E2 will be caught here.
 cout << "caught on E2 block" << endl;
 } catch (E1) {
 // This block will not run because the exception was already caught in the previous block.
 // However, it would run if the exception raised was of type E1.
 cout << "caught on E1 block" << endl;
 }
 try {
 cout << "Second block: ";
 throw E2{};
 } catch (E1) {
 // This block will run because E2 will be caught here.
 cout << "caught on E1 block" << endl;
 } catch (E2) {
 // This block will never run. Any exception of types E1 or E2 will be handled by the block above.
 cout << "caught on E2 block" << endl;
 }
}
```

### Catching Exceptions by reference
- when using a catch block to catch an exception based on the **superclass** (i.e. catch (E1)), the object is **sliced** into the superclass type
  - if you have polymorphic methods in the classes, the methods that will run will be based on superclass

```cpp
class E1 {
 public:
 virtual void f() {
 cout << "E1" << endl;
 }
};
class E2: public E1 {
 public:
 void f() override {
 cout << "E2" << endl;
 }
};
int main() {
 try {
 throw E2{};
 }
 catch (E1 e) {
 e.f();
 }
}
```

To use correct class: **catch exception by reference**

```cpp
int main() {
 try {
 throw E2{};
 }
 catch (E1 & e) {
 e.f();
 }
}
```

### Rethrow exceptions in class hierachy

- recall: rethrow exception using throw; or throw s;, where s is a variable where caught exception was stored
  - differs if exception is a subclass and the exception handler caught is an object of superclass

i.e.
```cpp
class SomeErrorType {};
class SpecialErrorType : public SomeErrorType {};
try {
 . . . // some code that raises a SpecialErrorType exception
}
catch (SomeErrorType s) { // note that we're catching a SomeErrorType exception, not a SpecialErrorType
 . . .
 throw; // will rethrow the original SpecialErrorType exception
 // throw s; // would throw the original exception sliced as a SomeErrorType
}
```

