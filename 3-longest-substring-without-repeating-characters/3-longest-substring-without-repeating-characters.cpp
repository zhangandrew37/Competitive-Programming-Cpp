class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen = 0;
        int l = 0, r = 0;
        unordered_map<char, int> freq;
        
        while (r < s.length()){
            if (freq[s[r]] != 0){
                while (l <= r && s[l] != s[r]){
                    freq[s[l]]--;
                    l++;
                }
                freq[s[l]]--;
                l++;
            } 
            
            maxlen = max(maxlen, r - l + 1);
            freq[s[r]]++;
            r++;
        }
        
        return maxlen;
    }
};

// dvdf
// l
//   r

// pwwkew
// l
//   r

// babbab
//  l
//    r

// cur: 1
// max: 1
// chars: a, b, c 