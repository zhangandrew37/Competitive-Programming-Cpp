class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> freqT;
        int len = s.length();
        int minLength = len + 1, minStart = 0;
        for (char c: t){
            freqT[c]++;
        }
        
        int l = 0, r = 0;
        int counter = t.length();
        
        
        while (r < len){
            if (freqT[s[r]] > 0) counter--;
            
            freqT[s[r]]--;
            r++;
            
            while (counter == 0){
                if (r - l < minLength){
                    minLength = r-l;
                    minStart = l;
                }
                
                freqT[s[l]]++;
                
                if (freqT[s[l]] > 0) counter++;
                l++;
            }
        }
        
        if (minLength == len + 1) return "";
        return s.substr(minStart, minLength);
    }
};