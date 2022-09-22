class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.length() - 1;
        
        while (l < r){
            // shift pointers if non-alphanumeric
            while (!isalnum(s[l])){
                l++;
                if (l == r) return true;
            } 
            while (!isalnum(s[r])) {
                r--;
                if (l == r) return true;
            }
            
                
            if (tolower(s[l]) != tolower(s[r])) return false;
            l++;
            r--;
        }
        
        return true;
    }
};

// race a car
//   l    r