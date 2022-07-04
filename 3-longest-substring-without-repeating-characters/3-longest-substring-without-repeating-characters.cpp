class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // frequency array + sliding window approach:
        // if character not in frq, frq[char]++;
        
        int frq[256];
        memset(frq, 0, sizeof(frq));
        
        int l = 0, len = s.length(), res = 0;
        for (int r = 0; r < len; r++) {
            frq[s[r]]++;
            
            //condition: want that frq[s[r] is <= 1
                // otherwise, get rid of chars from start one by one until frq = 1
                // increment left by 1 each char u get rid of
                // also decrease frq of that char
            //update res = max (res, curSubstringLength) <-- r-l+1
            while (frq[s[r]] > 1){
                frq[s[l]]--;
                l++;
            }
            
            res = max(res, r-l+1);
        }
        return res;
    }
};