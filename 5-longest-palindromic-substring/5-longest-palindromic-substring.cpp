class Solution {
public:
    string longestPalindrome(string s) {
        int res_l = 0, res_r = 0;
        
        int len = s.length();
        for (int i = 0; i < len; i++){
            // check odd
            int l = i, r = i;
            while (l >= 0 && r < len && s[l] == s[r]){
                if (r - l + 1 > res_r - res_l + 1){
                    res_l = l;
                    res_r = r;
                }
                l--;
                r++;
            }
            
            // check even
            l = i, r = i+1;
            while (l >= 0 && r < len && s[l] == s[r]){
                if (r - l + 1 > res_r - res_l + 1){
                    res_l = l;
                    res_r = r;
                }
                l--;
                r++;
            }
        }
        
        return s.substr(res_l, res_r - res_l + 1);
        
    }
};