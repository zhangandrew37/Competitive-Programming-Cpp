class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> frq;
        
        int l = 0, res = 0;
        
        for (int r = 0; r < s.size(); r++){
            while (frq[s[r]] == 1) {
                frq[s[l]]--;
                l++;
            }
            
            res = max(res, r - l + 1);
            frq[s[r]]++;
        }
        
        return res;
    }
};

/*

"abcabcbb"
 l
 r
 
*/