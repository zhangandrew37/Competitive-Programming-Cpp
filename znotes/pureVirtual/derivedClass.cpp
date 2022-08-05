#include <iostream>
using namespace std;

/* vvv      This would be in AbstractClass.h       vvv */
class AbstractClass {
  int integer;

  public:
    explicit AbstractClass(int);
    virtual void aPureVirtualMethod() = 0;
};

/* vvv      This would be in AbstractClass.cpp       vvv */
AbstractClass::AbstractClass(int integer): 
    integer{integer}
{
  // Constructor's Body
}

/* vvv      This would be in ConcreteClass.h       vvv */
class ConcreteClass {
  int integer;

  public:
    explicit ConcreteClass(int);
    void notAPureVirtualMethod();
};

/* vvv      This would be in ConcreteClass.cpp       vvv */
ConcreteClass::ConcreteClass(int integer): 
    integer{integer}
{
  // Constructor's Body
}

void ConcreteClass::notAPureVirtualMethod() {
  cout << "This is not pure virtual method" << endl;
}

/* vvv      This would be in DerivedClass.h       vvv */
class DerivedClass : public AbstractClass {
  int derivedInteger;

  public:
    explicit DerivedClass(int, int);
    void aPureVirtualMethod() override;
};

/* vvv      This would be in DerivedClass.cpp       vvv */
DerivedClass::DerivedClass(int abstractInteger, int derivedInteger):
  AbstractClass{abstractInteger}, derivedInteger{derivedInteger}
{
  // Constructor's Body
}

void DerivedClass::aPureVirtualMethod() {
  cout << "Implementing aPureVirtualMethod" << endl;
}

/* vvv      This would be in main.cpp       vvv */
int main() {
  ConcreteClass concreteClass {5};
  concreteClass.notAPureVirtualMethod();

  DerivedClass derivedClass {1, 2}; 
  derivedClass.aPureVirtualMethod();

  return 0;
}
