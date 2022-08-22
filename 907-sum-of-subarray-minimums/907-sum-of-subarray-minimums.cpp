class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        long long sum = 0;
        int len = arr.size();
        stack<int> st; // increasing monotone
        vector<int> nextLess(len, len); // lesser or equal
        vector<int> prevLess;
        
        for (int i = 0; i < len; i++){
            while (!st.empty() && arr[i] < arr[st.top()]){
                nextLess[st.top()] = i; // element being popped' next less is i 
                st.pop();
            }
            int p = st.empty() ? -1 : st.top();
            prevLess.push_back(p);
            st.push(i);
        }
        
        for (int i = 0; i < len; i++){
            int l = i - prevLess[i];
            int r = nextLess[i] - i;
            sum += (long long) l * r * arr[i];
        }
        return sum % 1000000007LL;
    }
};