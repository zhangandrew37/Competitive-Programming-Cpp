class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        
        unordered_map<char, int> freqS, freqT;
        for (int i = 0; i < s.length(); i++){
            freqS[s[i]]++;
            freqT[t[i]]++;
        }
        
        for (auto c: freqS){
            if (c.second != freqT[c.first]) return false;
        }

        return true;
    }
};