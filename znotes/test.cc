#include <iostream>


struct A {
  A() { std::cout << "A ctor" << std::endl; }
  ~A() { std::cout << "A dtor" << std::endl; }
};

struct B : public A {
  B() { std::cout << "B ctor" << std::endl; }
  ~B() { std::cout << "B dtor" << std::endl; }
};


int main() {
  B b;
  A* a = new B;
  delete a;
}