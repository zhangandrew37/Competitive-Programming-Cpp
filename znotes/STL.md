## Standard Template Library (STL)

### Vectors

- v[i] is unchecked -> out of bounds behaviour is undefined
- v.at(i) throws an out_of_range exception

```cpp

#include <vector>

vector<int> v;
v.emplace_back(5); // emplace back creates a new object by using class constructor efore adding to array
v.push_back(6); // push back moves the content from an existing object into the array

```

You can use a for loop to visit a vector's contents by indexing:

```cpp
for (std::size_t i = 0; i < v.size(); ++i) {
 cout << v[i] << endl;
}
```

Vectors also support the **iterator abstraction:**
```cpp
for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
 cout << *it << endl;
}
```

Or simply: 
```cpp
for (auto n : v) {
 cout << n << endl;
}
```

### Map

```cpp

//init:

map<string, int> m;
m["abc"] = 1;

// erase: 

m.erase("abc");

// count:

if (m.count("def") == 0){
...
}

// iterate:

for (auto &p: m) {
    cout << p.first << p.second;
}
```