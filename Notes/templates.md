## Templates

- note: implementation of template needs to go into .h 
- allows us to create parameterized classes (**templates**) 
- generate many concrete classes without duplicating code

### List template:
```cpp
template <typename T> class List {
 struct Node {
T data;
 Node *next;
. . .
 };
 Node *theList;
 public:
 . . .
};
```

- parameter T: when program executed, each instance of T in code is replaced with actual type

i.e.
```cpp
List<int> li; 
li.addToFront(1);
List<string> ls;
ls.addToFront("hello");
```

or 

```cpp
template <typename K, V> class Dictionary {
 K key;
 V value;
 . . .
}
Dictionary<string, Student> d;
```