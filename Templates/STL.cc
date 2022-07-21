#include <iostream>
#include <map>
#include <vector>
#include <utility
#include <iterator>
#include <algorithm>

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

// ---- vector ----
vector<int> v = {1,2,3};

// sort
sort(v.begin(), v.end());

// ---- string ----
string s = "";

// check if empty
if (s.empty()){} 
      //or 
if (s.length() == 0)
      //or
if (s.size() == 0)

// Algorithms  

// ---- for_each ----
// - applies function fn to each element in range [first, last]

template<class InputIterator, class Function>
 Function for_each(InputIterator first, InputIterator last, Function fn)
{
 while (first!=last) {
 fn (*first);
 ++first;
 }
 return fn; // or, since C++11: return move(fn);
}

//usage:

void addOne(int &n) { ++n; }
. . .
vector<int> v { ... };
for_each(v.begin(), v.end(), addOne); // calls addOne for each element in the vector

// ---- find ----
// find returns an iterator to the first element in the range [first,last) that compares equal to val. If no such
//    element is found, the function returns last

int myints[] = { 10, 20, 30, 40 };
int * p = find (myints, myints+4, 30); // p points to the element 30 in the array

// ---- count ----
// count returns the number of elements in the range [first,last) that compare equal to val.

// Note: The return type (iterator_traits<InputIterator>::difference_type) is a signed integral type.
// Usage example:
int myints[] = {10,20,30,30,20,10,10,20}; // 8 elements
int mycount = count (myints, myints+8, 10); // mycount = 3

// ---- copy ----
// copy copies the elements in the range [first,last) into the range beginning at result. It returns an iterator to
    // the end of the destination range (which points to the element following the last element copied).

// Usage: 
// Note: copy does not allocate new memory, so the output container must already have enough space available.
vector<int> v {1,2,3,4,5,6,7};
vector<int> res(4); // space for 4 ints
vector<int> res_wrong; // WRONG! no space available in res_wrong
copy(v.begin() + 1, v.begin() + 5, res.begin()); // res = {2,3,4,5}

// also can do: 
// (back_inserter calls push_back to allow adding new items)
vector<int> v {1, 2, 3, 4, 5};
vector<int> w;
copy(v.begin(), v.end(), back_inserter(w)); // works

// ---- transform ----
// transform applies an operation op to each of the elements in the range [first,last) and stores the value
// returned by each operation in the range that begins at result. It's similar to copy, except that it applies the
// operation op to each element being copied.

// Note: like copy, transform does not allocate new memory, so the output container must already have enough space
//   available, or you can use a back inserter to add new elements to the output container.

// Usage:
int add1(int n) { return n + 1; }
. . .
vector <int> v {2, 3, 5, 7, 11};
vector <int> w(v.size());
transform(v.begin(), v.end(), w.begin(), add1); // w = {3, 4, 6, 8, 12}