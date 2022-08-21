class MinStack {
public:
    stack<int> st, mn;
    int curMin;
    
    MinStack() {
        curMin = INT_MAX;
    }
    
    void push(int val) {
        mn.push(curMin);
        st.push(val);
        curMin = min(curMin, val);
    }
    
    void pop() {
        int n = st.top();
        if (n == curMin){
            curMin = mn.top();
        }
        st.pop();
        mn.pop();
    }
    
    int top() {
       return st.top(); 
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