class Solution {
public:
    void sortColors(vector<int>& nums) {
        int len = nums.size();
        int i = 0, l = 0, r = len - 1;
        while (i <= r) {
            if (nums[i] == 0){
                swap(nums[i], nums[l]);
                l++;
                
            } else if (nums[i] == 2){
                swap(nums[i], nums[r]);
                r--;
                i--; // don't increment i
            }
            i++;
        }
        
    }
};

// solution 1: store number r, w, b in array and bucket sort (not O(1) space but O(n))