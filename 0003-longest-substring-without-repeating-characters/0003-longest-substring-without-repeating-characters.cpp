class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> pos(256, -1);
        
        int l = -1, res = 0;
        
        for (int r = 0; r < s.size(); r++){
            if (pos[s[r]] > l) { // if current char already in substring
                l = pos[s[r]];
            }
            pos[s[r]] = r;
            res = max(res, r - l);
        }
        
        return res;
    }
};

/*

"abcabcbb"
 l
 r
 
*/