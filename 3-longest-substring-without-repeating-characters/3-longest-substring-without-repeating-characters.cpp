class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen = 0;
        int l = 0;
        unordered_map<char, int> freq;
        int len = s.length();
        
        for (int r = 0; r < len; r++){
            freq[s[r]]++;
            while (freq[s[r]] > 1){
                freq[s[l]]--;
                l++;
            }
            
            maxlen = max(maxlen, r - l + 1);
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