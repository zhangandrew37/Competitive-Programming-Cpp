class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        
        while (l < r){
            int m = (l + r) / 2;
            if (nums[l] < nums[m]) { // first half sorted, include middle
                if (nums[l] <= target && target <= nums[m]){
                    r = m;
                } else {
                    l = m + 1;
                }
            } else { // second half sorted, exclude middle
                if (nums[m + 1] <= target && target <= nums[r]){
                    l = m + 1;
                } else {
                    r = m;
                }
            }
        }
        
        return nums[l] == target ? l : -1;
    }
};