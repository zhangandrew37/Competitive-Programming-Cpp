# Big Five

## Constructor (not part of rule of 5)
- pro: don't need to write assignment operator for objects
```cpp
Student::Student(int assn, int mt): assn{assn}, mt{mt}{}
```

## Destructor
- delete any heap-allocated memory
  - pointers
  - dynamic arrays
```cpp
Student::~Student(){}
```

## Copy Constructor
 ```cpp
 Node(const Node &other){
    data = other.data;
    if (other->next != nullptr){
        next = other->next;
    } else {
        next = nullptr;
    }
 }
 ```
## Move Constructor
```cpp
// MIL Style
Node(const Node &&other): data{other.data}, next{other.next}{
    other.next = nullptr;
}
 ```
## Copy Assignment Operator
```cpp
// write swap function
void swap(Node & other){
    std::swap(data, other.data);
    std::swap(next, other.next);
 }

 Node &operator=(const Node *other){
    Node tmp{other};
    swap(tmp);
    return *this;
 }
 ```

## Move Assignment Operator
- don't need tmp since we know rvalue destroyed soon
```cpp
Node &operator=(Node && other){
    swap(other);
    return *this;
}
 ```

 