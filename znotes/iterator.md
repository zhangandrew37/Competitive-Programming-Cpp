## Iterator

General format:

```cpp
// Iterator:
class MyClassIterator{
    // (private) field to keep track of where iterator is currently pointing at
    
    explicit MyClassIterator(/* parameter to initialize*/) // private ctor

    public:
        MyClass &operator*(); // access item iterator is currently pointing at, can be diff. return type
        MyClassIterator &operator++(); // advances iterator, returns iterator
        bool operator==(const MyClassIterator &other) const;
        bool operator !=(const MyClassIterator &other) const;
}

// Class:

class MyClass{
    public:
        MyClassIterator begin();
        MyClassIterator end();
}

```

### Example with LinkedList

```cpp
class List {
    struct Node;
    Node *theList;

    public:
        class Iterator {
            Node *p;
            explicit Iterator(Node *p): p{p}{}

            private: 
            int &operator*(){
                return p->data;
            }
            Iterator &operator++(){
                p = p->next;
                return *this;
            }

            bool operator==(const Iterator &other) const {
                // Iterators are equal if pointers are equal
                return (p == other.p);
            }

            bool operator!=(const Iterator &other) const {
                return !(*this==other);

            }
            friend class List; // give access to all Iterator members
        }

        Iterator begin(){
            return Iterator{theList};
        }

        Iterator end(){
            return Iterator{nullptr} // thing after end
        }

}
```

Using the iterator:

```cpp
int main() {
    List lst;
    lst.addToFront(3);
    for (List::Iterator it = lst.begin(); it != lst.end(); ++it){
        cout << *it;
    }
}
```

Range-based for-loops

```cpp
for (auto n: lst){
    cout << n;
}

for (auto &n: lst){ // declare n by ref, allows mutation
    ++n;
}
```

for_each

```cpp
void f (int n) { cout << n << endl; }
. . .
int a [] = {1, 2, 3, 4, 5};
. . .
for_each(a, a+5, f); // prints the array
```