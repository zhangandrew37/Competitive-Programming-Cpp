class Solution {
public:
    string minWindow(string s, string t) {
        int slen = s.length(), tlen = t.length();
        if (tlen > slen) return "";
        unordered_map<char, int> frq;
        
        int l = 0, minL = -1, minR = slen, cnt = 0;
        
        for (auto c : t) frq[c]++;
        
        for (int r = 0; r < slen; r++) {
            if (frq[s[r]] > 0) cnt++; // when cnt == tlen, we have valid window
            frq[s[r]]--; // since we will increment r
            
            while (cnt == tlen) {
                if (r - l < minR - minL){
                    minL = l;
                    minR = r;
                }
                
                if (++frq[s[l]] > 0) cnt--; // since we increment l, we lose one
                l++;
            }
            
            
        }
        
        return minL == -1 ? "" : s.substr(minL, minR - minL + 1);
    }
};

/*

"abc"
 l
   r
"c"

*/