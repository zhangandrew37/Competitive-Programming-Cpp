# Polymorphism

 A class that declares or inherits a virtual function is a polymorphic class

 - At run time, objects of a derived class may be treated as objects of a base class 
   - in places such as method parameters or arrays
 - Never use arrays of objects polymorphically
   - data misaligned
   - always use pointers

# Virtual

calling using pointers or references:
- A call to a virtual function is resolved according to underlying type of object for which it is called
- A call to non-virtual function is resolved according to the type of the pointer/reference

Note: superclass cannot be "converted" to derived class type

calling not using pointers or references: (i think this is how it works)
- A call to virtual function is resolved based on current object type
- A call to non-virtual function is resolved based on (i.e.) parameter type