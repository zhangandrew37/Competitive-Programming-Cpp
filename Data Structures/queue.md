# Queue (FIFO)

Elements are:
- inserted from the **back/end** 
- deleted from the **front**

Use when:
- you want to get things out in the order you put them in

### Syntax:

```cpp
queue<int> q;
```

### Functions:
- All operations are **O(1)** time complexity except **swap** (**O(n)**)
```cpp
q.empty();
q.size();
q.swap(); // O(n): swaps contents of two queues (same data type, but can be different sizes)
q.emplace();
q.front();
q.back();
q.push(g);
q.pop();