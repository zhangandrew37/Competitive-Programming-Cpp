class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.length(); i++){
            if (s[i] == '(' || s[i] == '[' ||s[i] == '{'){
                st.emplace(s[i]);
            } else{
                if (st.empty()) return false;
                if(s[i] == ')') {
                    if (st.top() != '(') return false;
                } else if (s[i] == ']'){
                    if (st.top() != '[') return false;
                } else {
                    if (st.top() != '{') return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};