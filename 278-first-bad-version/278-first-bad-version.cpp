// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        
        if (isBadVersion(1)) return 1;
        
        int l = 2;
        int r = n - 1;
                
        while (l <= r){
            int m = l + (r - l)/2;
            if (!isBadVersion(m - 1) && isBadVersion(m)) return m;
            
            if (isBadVersion(m)){ // first bad version is to the left, update r
                r = m - 1;
            } else { // both m - 1 and m aren't bad, update l
                l = m + 1;
            }
        }
        return n;
    }
};

// 