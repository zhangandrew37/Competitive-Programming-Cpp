## Advanced Casts

- converting one piece of data to another

General format: ```the_cast<type>(val)```
1. ```static_cast```
2. ```const_cast```
3. ```reinterpret_cast```
4. ```dynamic_cast```

### **static_cast**

- for "sensible casts" with **well defined** behaviour

Int to double
- double can store all number int can
```cpp
double d{3.2};
void f(int x);

f(static_cast<int>(d));
```

**Downcasting**
- casts from supertype to subtype

i.e. Full Text * to Book*
- every FullText* is a Book*
  - i.e. ```class FullText: public Book```
```cpp
FullText *f = static_cast<FullText *> (b);
```

### **reinterpret_cast**

- ex. all pointers to point some address in memory with numeric value
- reinterpret it as its numerical value

```cpp
reinterpret_cast<long>(b);
```

```cpp
Book *b = new Book("I Know Why the Caged Bird Sings", "Maya Angelou");
FrenchTranslation *f = reinterpret_cast<FrenchTranslation *>(b);
```
### **const_cast**

- cast const away

```cpp
const Book *b = [...];
getTitleLength(const_cast<Book *>(b));
```

### **dynamic_cast**

- checked cast: 
  - allows downcasts like static_cast
  - actually checks if object is of given type
  - otherwise: nullptr

- highly coupled to the Book, would need to change code each time we change the hierachy

### **Smart pointers**

```cpp
 shared_ptr<FullText> f = dynamic_pointer_cast<FullText>(b); 
```

### **Fixing polymorphic assignment with dynamic cast and exception handlers**

Recall:
1. **Public non-virtual** operations do not restrict what the programmer can do but allow partial assignment
2. **Public virtual** operations do not restrict what the programmer can do but allow mixed assignment
3. **Protected operations** in an abstract superclassthat are called by the public operations in the concrete subclasses
prevent partial and mixed assignments but prevent the programmer from making assignments using base class
pointers.

However, (2) creates a problem when we do:
```cpp
Text t { . . . };
Comic c { . . . };
t = c; 
```
### **Fix**:

Recall: 

```cpp
Text &operator=(const Book &rhs) override;
Text &operator=(Book &&rhs) override;
```
- We can use dynamic cast to treat object passed by reference as the proper parameters to the copy/move assignment operators
  - treat Text& as Book&
  - If object passed is not an instant of Text, dynamic cast will throw ```std::bad_cast``` exception

We now have:

Copy constructor:
```cpp
Text &Text::operator=(const Book &other){
    if (this == &other) return *this;
    Book::operator=(other);

    // attempt to treat rhs as Text object using dynamic_cast (if not, exception thrown)
    const Text &tmp = dynamic_cast<const Text&>(other);
    topic = tmp.topic;
    return *this;
}
```

```cpp
Text &Text::operator=(Book &&other){
    if (this == &rhs) return *this;
    Book::operator=(other);
    Text &tmp = dynamic_cast<Text&>(other);
    topic = std::move(tmp.topic);
    return *this;
}
```

### Handling std::bad_cast

```cpp
try{
    *pb2 = *pb1;
} catch (std::bad_cast r{
    cerr << r.what() << endl;
})
```