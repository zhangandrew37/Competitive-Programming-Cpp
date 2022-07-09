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

// ---- LinkedList ----
// - remember to initialize values
// - memory management
// - check nullptr

// traversal:
struct node *tmp = head;
while (tmp != nullptr){
    cout << tmp->data << endl;
    tmp = tmp->next;
}

//addToFront (n):
struct node *tmp = new node;
tmp->data = n;
tmp->next = head;
head = tmp;

//addToPos(pos, n):
struct node *newNode = new node;
newNode->data = n;

struct node *tmp = head;
for (int i = 1; i < pos; i++){
    if (tmp->next != nullptr){
        tmp = tmp->next;
    }
}

newNode->next = tmp->next;
tmp->next = newNode;

//deleteFromPos(pos):
 node *ret = head;
for (int i = 1; i < pos; i++){ // finding prev
    if (head->next != nullptr){
        head = head->next;
    }
}

node *next = head->next->next;
delete(head->next);
head->next = next;

//delete Linkedlist
while (head != nullptr){
    head = head->next;
}