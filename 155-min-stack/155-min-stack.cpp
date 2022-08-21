class MinStack {
public:
    stack<pair<int, int>> st;
    int curMin;
    
    MinStack() {
        curMin = INT_MAX;
    }
    
    void push(int val) {
        st.push({val, curMin});
        curMin = min(curMin, val);
    }
    
    void pop() {
        int n = st.top().first;
        if (n == curMin){
            curMin = st.top().second;
        }
        st.pop();
    }
    
    int top() {
       return st.top().first; 
    }
    
    int getMin() {
        return curMin;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */