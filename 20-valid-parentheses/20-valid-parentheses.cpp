class Solution {
public:
    bool isValid(string s) {
        stack<char> chars;
        for(int i = 0 ; i < s.length(); i++){
            if (s[i] == '(' || s[i] == '[' || s[i] == '{'){
                chars.push(s[i]);
            } else {
                if (chars.empty()) return false;
                if (s[i] == ')'){
                    if (chars.top() != '(') return false;
                } else if (s[i] == ']'){
                    if (chars.top() != '[') return false;
                } else {
                    if (chars.top() != '{') return false;
                }
                chars.pop();
            }
            }
        
        return chars.empty();
    }
};