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

// ---- Stack ----
// type of caontiner adapter with LIFO
// uses encaspulated obejct of either vector, dequeue or list as its underlying container
// (provides member functions to access its elements)

// Container: type of underlying container object
template<class Type, class container = deque<Type>> class stack;

//ex: 
stack<int> stack;

// empty() – Returns whether the stack is empty – Time Complexity : O(1) 
// size() – Returns the size of the stack – Time Complexity : O(1) 
// top() – Returns a reference to the top most element of the stack – Time Complexity : O(1) 
// push(g) – Adds the element ‘g’ at the top of the stack – Time Complexity : O(1) 
// pop() – Deletes the top most element of the stack – Time Complexity : O(1) 
// swap() - 
stack1.swap(stack2);
// emplace() - Push but for creating elements on place

// ---- Deque ----
// double ended queue (expansion and contraction on both ends)
// more efficient in case of insertion and deltion of elements at beginning/end compared to vectors