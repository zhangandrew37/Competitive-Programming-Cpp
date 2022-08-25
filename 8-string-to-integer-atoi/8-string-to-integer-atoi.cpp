class Solution {
public:
    int myAtoi(string s) {
        if (s.empty()) return 0;
        
        int slen = s.length();
        long long ans = 0;
        int i = 0;
        bool neg = false;
        while(i < slen && s[i] == ' ') i++;
        if (s[i] == '-'){
            neg = true;
            i++;
            if (s[i] == '+') return 0;
        }
        if (s[i] == '+') {
            neg = false;
            i++;
        }
        while (s[i] >= '0' && s[i] <= '9'){
            ans *= 10;
            if (ans <= INT_MIN || ans >= INT_MAX){
                break;
            }
            ans += (s[i] - '0');
            i++;
        }
        
        if (neg == true) ans *= -1;
        if (ans <= INT_MIN) return INT_MIN;
        if (ans >= INT_MAX) return INT_MAX;
        
        return (int) ans;
    }
}; 

// why dont you need to check for bounds?