class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> freq;
        int len = 0;
        for(char c: s){
            freq[c]++;
            if(freq[c] % 2 == 0) len+=2;
        }
        int slen = s.length();
        return min(slen, len + 1);
    }
};

// want even counts (pairs)
// if newlen != len, then return newlen+1 cause we can have random character in the middle