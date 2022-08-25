class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> freq;
        int cnt = 0;
        for (char c: s){
            freq[c]++;
            if (freq[c] == 1) cnt++;
        }
        
        for (char c: t){
            if (freq[c] == 0) return false;
            freq[c]--;
            if (freq[c] == 0) cnt--;
        }
        
        return cnt == 0;
    }
};