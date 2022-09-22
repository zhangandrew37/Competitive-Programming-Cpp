# Monotonic stack

- **Monotonically increasing:** always increasing
- use to find the previous greater and next greater elements of an array in linear time
- i.e. for decreasing, if we have [1,2,3] and need to push 5, we will have to pop everything, so our list becomes [5]

<br>

### Finding previous greatest:

i.e. (monotone decreasing)
- whatever is underneath of element in stack is **previous greatest**

```
Given: {1, 3, 10, 7, 5, 24, 4}

1. [] -> [1]
2. [1] -> [3] // since 3 >= 1
3. [3] -> [10]
4. [10] -> [10, 7] // 10 is prev greatest of 7
```

### Finding next greatest 

- just start from the end of the list, i.e. {4, 24, 5, 7, 10, 3, 1}

> **Use monotone increasing for prev lesser, next lessser**

<br>

### Decreasing stack: **previous greater**

```cpp
vector<int> arr {1, 3, 10, 7, 5, 24, 4};
stack<int> st;
vector<int> prevGreater; // prevGreater for each element in arr

for (int i = 0; i < arr.size(); i++){
    while (!stack.empty() && arr[st.top() <= arr[i]]){
        st.pop();
    }

    int prev = st.empty() ? -1 : st.top(); 
    prevGreater.push_back(prev);

    st.push(i); // want to push indexes 
}
```

- for **next greater**, we simply just go from i = arr.size() - 1 down to i >= 0


### Get both previous greater or equal AND next greater:
> one of previous greater or next greater has to be greater or equal than
- whatever element is pushed is the next greater than whichever is popped 
  - i.e. [20, 15], push 17, becomes [20, 17] and 15's next greater is 17
```cpp
vector<int> arr {1, 3, 10, 7, 5, 24, 4};
stack<int> st;

int len = arr.size();
vector<int> nextGreater(len, -1); // -1 if none
vector<int> prevGreaterOrEqual; 

for (int i = 0; i < arr.size(); i++){
    while (!stack.empty() && arr[st.top() < arr[i]]){
        nextGreater[st.top()] = i;
        st.pop();
    }

    int prev = st.empty() ? -1 : st.top(); 
    prevGreaterOrEqual.push_back(prev);

    st.push(i); // want to push indexes 
}
```