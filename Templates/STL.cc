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
// template <class InputIterator, class T>
 typename iterator_traits<InputIterator>::difference_type
count (InputIterator first, InputIterator last, const T& val)
{
 typename iterator_traits<InputIterator>::difference_type ret = 0;
 while (first!=last) { 
 if (*first == val) ++ret;
 ++first;
 }
 return ret;
}
// Note: The return type (iterator_traits<InputIterator>::difference_type) is a signed integral type.
// Usage example:
int myints[] = {10,20,30,30,20,10,10,20}; // 8 elements
int mycount = count (myints, myints+8, 10); // mycount = 3