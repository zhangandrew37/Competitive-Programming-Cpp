class Solution {
public:
    string longestPalindrome(string s) {
        int maxl = 0, maxr = 0;
        int len = s.length();
        
        for (int i = 0; i < len; i++){
            // even
            int l = i, r = i;
            
            // l and r are middle, go outwards
            while (l >= 0 && r < len && s[l] == s[r]){
                if (r - l > maxr - maxl){
                    maxr = r;
                    maxl = l;
                }
                l--;
                r++;
            }
            
            // odd
            l = i, r = i + 1;
            
            // l and r are middle, go outwards
            while (l >= 0 && r < len && s[l] == s[r]){
                if (r - l > maxr - maxl){
                    maxr = r;
                    maxl = l;
                }
                l--;
                r++;
            }
        }
        
        return s.substr(maxl, maxr - maxl + 1);
    }
};