class Solution {
public:
    
    bool canEat(vector<int>& piles, int k, int h){
        int cur = 0;
        for (auto i : piles){
            cur += ceil(i/(double)k);
        }
        return cur <= h ? true : false;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = piles[0];
        for (auto i : piles){
            l = min(l, i);
            r = max(r, i);
        }
        
        int res = r;
                
        while (l < r){
            int k = (l + r) / 2;
            if (canEat(piles, k, h)){
                r = k;
                res = min(res, r);
            } else {
                l = k + 1;
            }
        }
        
        return l;
    }
};

/*

[3,6,7,11]

[3,6]

binary search on k
- l = 3
- r = 11

=> check if that k satisfies our condition
=> O(nlogn)
=> we also need to sort to find 

*/