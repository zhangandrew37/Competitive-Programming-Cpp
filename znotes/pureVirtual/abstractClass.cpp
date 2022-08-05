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


/* vvv      This would be in main.cpp       vvv */
int main() {
  AbstractClass abstractClass {1}; // This one is not instanciable
  ConcreteClass concreteClass {2}; 
  concreteClass.notAPureVirtualMethod();

  return 0;
}
