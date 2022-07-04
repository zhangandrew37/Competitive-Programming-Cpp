//optimize later
//.find is not constant lookup

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        string res = "";
        int maxLength = 0;
        int l = 0;
        int r = 0;
        
        while (l <= r && r < len){
            if (res.find(s[r]) == -1){
                res += s[r];
                r++;
            } else {
                l++;
                res = s.substr(l, r-l+1);
            }
            int curlen = res.length();
            maxLength = max(maxLength, curlen);
        }
        return maxLength;
    }
};