## Compilation Dependencies

(forward declarations)

Consider class A, defined in file a.h.

There are 5 possible ways A can be used by another class.


```cpp
class B : public A {
 ...
}
```
- **include a.h**:  compiler needs to know size of A to determine size of B

<br>

```cpp
class C {
    A myA;
}
```
- **include a.h**:  compiler needs to know size of A to determine size of B

<br>

```cpp
class D {
    A *Aptr;
}
```
- **forward declaration**:  all pointers are the same size
- **include a.h in d.cc**

<br>

```c++
class E {
    A f(A x);
}
```
- **forward declaration**:  method signature (i.e. parameter and return value // by value) is only used for type checking by compiler 
  - no true compilation dependency
- **include a.h in e.cc**

<br>

```cpp
class F{
    void f() {
        A x;
        x.someMethod();
    }
}
```
- **include  a.h**: in this case, we wrote the implementation for F::f inline (which is discouraged) using a method that belongs to A
  - compiler knows what methods A has available
- **include a.h in e.cc**

<br>

## Notes
- can also forward declare for type **struct**
- forward declarations can remove include cycles
- will not remove them when inclusion is absolutely necessary
  - inheritance, object as a data field

## Inlcude cycle due to inheritance

**File**: a.h
```cpp
#ifndef A_H
#define A_H
#include "b.h"
class A : public B {
 ...
};
#endif
```

**File**: b.h
```cpp
#ifndef B_H
#define B_H
#include "a.h"
class B : public A {
 ...
};
#endif
```
- conceptually, we can't have A inherit from B AND B inherit from A
  - can replace "is a" relationship with "has a relationship (i.e. composition instead of inheritance)

i.e.
```cpp
class A{
  B myB;
  ...
};
```

## Fix: 

**File**: a.h

```cpp
#ifndef A_H
#define A_H
class B;
class A {
 B *myB;
 ...
};
#endif
```

**File**: b.h

```cpp
#ifndef B_H
#define B_H
class A;
class B {
 A &myA;
 ...
};
#endif
```
- make data field a reference or pointer to to the object (instead of **being** the object).
  - can use forward declr. since we know ptr size