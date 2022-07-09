#include <iostream>
#include <map>
#include <vector>
#include <utility

// set arr elements to a value
// Time: O(n)
// memset (void * ptr, int value, size_t num);
    // ptr: pointer to block of memory to fill
    // value: to set 
    // num: num bytes to set to the value
memset(arr, 0, sizeof(arr));

// substr (void)
// Time: O

// ----  map (ordered) --- 
map<string, int> m;

//Use:

// setting elements
m["key"] = 1;
// output:
cout << m["keyNotInMap"] << endl; // outputs: 0  because if the key is not found, it is default constructed with value 0 (for int)
// erase:
m.erase ("key");
// find/count (use find)
if (m.count("def")) ... // 0 = not found, 1 = found
if (m.find("key") != m.end()) ...

// iterating (sorted by key order)
for (auto &p : m){
    // p's type is: pair<string, int>&
    cout << p.first << p.second << endl;
}

// ----  map (unordered) --- 
unordered_map<int, int> m;

// can iterate through key-value pairs (lambda function)

// insert
m.insert(pair<int, int>(nums[i], i));
