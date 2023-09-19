class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> frq;
        int res = 0, l = 0;
        char mostFrq = s[0];
        
        for (int r = 0; r < s.size(); r++){
            if (++frq[s[r]] > frq[mostFrq]) mostFrq = s[r];
            while (r - l + 1 - frq[mostFrq] > k) {
                frq[s[l]]--;
                l++;
                for (int i = 0; i < 26; i++){
                    if (frq['A' + i] > frq[mostFrq]) mostFrq = 'A' + i;
                }
            }
            res = max(res, r - l + 1);
        }
        
        return res;
    }
};

/*

"AABABBA", k = 1
  l  r

 A: 1
 B: 0
 len: 1
 most frq = A;
 len - frq[mostFrq] = 1;
 
 res = 0

*/