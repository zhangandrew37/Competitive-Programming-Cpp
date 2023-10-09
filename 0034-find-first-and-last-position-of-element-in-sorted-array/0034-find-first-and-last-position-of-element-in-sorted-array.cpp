class Solution {
public:
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        if (r == -1) return {-1, -1};
        
        while (l < r){
            int m = (l + r) / 2;
            if (nums[m] < target){
                l = m + 1;
            } else {
                r = m;
            }
        }
        
        // target not found
        if (nums[l] != target) return {-1, -1};
        
        int newL = l; // dont need to search below l
        r = nums.size() -1;
        
        while (newL < r){
            int m = (newL + r) / 2 + 1;
            if (nums[m] > target){
                r = m - 1;
            } else {
                newL = m;
            }
        }
        
        return {l, newL};
    }
};

/*

[5,7,7,8,8,10]
       l m.r

*/