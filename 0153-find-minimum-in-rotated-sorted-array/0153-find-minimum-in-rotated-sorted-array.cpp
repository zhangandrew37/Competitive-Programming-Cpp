class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        
        while (l < r){
            int m = (l + r) / 2;
            // cur array is sorted
            if (nums[l] < nums[r]) {
                break;
            } else { // find unsorted half
                // first half unsorted
                if (nums[l] > nums[m]) {
                    r = m;
                } else {
                    l = m + 1;
                }
            }
        }
        
        return nums[l];
    }
};

/*

[3,4,5,1,2]

*/