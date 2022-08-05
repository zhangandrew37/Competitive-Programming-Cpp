#include <iostream>
using namespace std;

/* vvv      This would be in DerivableClass.h       vvv */
class DerivableClass {
  int integer;

  public:
    explicit DerivableClass(int);
    virtual ~DerivableClass();
};

/* vvv      This would be in DerivableClass.cpp       vvv */

DerivableClass::DerivableClass(int integer):
	integer{integer}
{
	cout << "Constructing an instance of DerivableClass" << endl;
}

DerivableClass::~DerivableClass() {
	cout << "Destructing an instance of DerivableClass" << endl;
}

/* vvv      This would be in DerivedClass.h       vvv */
class DerivedClass : public DerivableClass {
	int* someIntegerOnTheHeap = nullptr;

  public:
    explicit DerivedClass(int, int);
    ~DerivedClass();
};

/* vvv      This would be in DerivedClass.cpp       vvv */

DerivedClass::DerivedClass(int integer, int someIntegerOnTheHeap):
	DerivableClass{integer}, someIntegerOnTheHeap{new int(someIntegerOnTheHeap)}
{
	cout << "Constructing an instance of DerivedClass" << endl;
}

DerivedClass::~DerivedClass() {
	cout << "Destructing an instance of DerivedClass" << endl;
	delete this->someIntegerOnTheHeap;
}

/* vvv      This would be in main.cpp       vvv */
int main() {
	cout << "Example 1: DerivableClass* derivableClass = new DerivableClass" << endl;
	DerivableClass* derivableClass = new DerivableClass {1};
	delete derivableClass;

	cout << endl << "Example 2: DerivedClass* derivedClass = new DerivedClass" << endl;
	DerivedClass* derivedClass = new DerivedClass {1, 2};
	delete derivedClass;

	cout << endl << "Example 3: DerivableClass* myDerivableClass = new DerivedClass" << endl;
	DerivableClass* myDerivableClass = new DerivedClass {1, 2};
	delete myDerivableClass;

	return 0;
}