# Comparator Function

O(n logn)
- sorting custom array of objects

Using custom compare function,
```cpp
static bool compare(const vector<int>&a, const vector<int>&b){
        return a[0] < b[0];
    }
```
Call sort:

```cpp
sort(arr.begin(), arr.end(), compare); // using Iterator and comparator function
```
