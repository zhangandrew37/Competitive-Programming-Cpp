# Multiple Inheritance

Problem: Diamond of Death

- we have 2 copies of a field (in B and C)
- i.e. ```dObj.a``` -> is this from B or C?
- can fix: ```dObj.B::a``` (but not fundamental problem)

Solution: make A a **virtual base class**

- B and C use **virtual inheritance**
  - all virtual destructors
  - "virtual public A"
```cpp
class A {
 public:
 int a = 100;
 A() {}
 virtual ~A(){}
};
class B: virtual public A {
 public:
 int b = 200;
 B() {}
 virtual ~B(){}
};
class C: virtual public A {
 public:
 int c = 300;
 C() {}
 virtual ~C(){}
};
class D: public B, public C {
 public:
 int d = 400;
 D() {}
 virtual ~D(){}
};
```