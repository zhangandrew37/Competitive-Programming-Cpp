class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        
        while (l < r){ // always exits when l == r
            int m = l + (r-l)/2;
            
            if (nums[m] < target) l = m + 1;
            else r = m;
        }
        
        return nums[l] == target ? l : -1;
    }
};