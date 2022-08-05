# Review

## Static Members

- use when we need to keep state or data across all objects of a class, rather than for each individual object
- can only access static fields and access other static methods

**File:** .h

```cpp
static int numInstances; // only declaration
static void howMany(){
    cout << numInstances << endl;
}
```

**File:** .cc

```cpp
static int numInstances = 0; // definition
Student::howMany(); // not tied to instance
```

Note: should not be freed as part of object destruction

### Object Slicing



