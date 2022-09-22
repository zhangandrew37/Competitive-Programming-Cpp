# Stack (LIFO)

- elements are added and removed **only** from the **top** 

Use when:
- you want to get things out in the **reverse** order you put them in
- 
### Syntax:

```cpp
template<class Type, class Container = dequeue<Type>> class stack;

stack<int> st;
```

### Functions:
- All operations are **O(1)** time complexity
```cpp
st.empty();
st.size();
st.top();
st.push(g);
st.pop();