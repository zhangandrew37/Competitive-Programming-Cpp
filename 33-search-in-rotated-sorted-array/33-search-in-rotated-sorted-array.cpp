class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r){
            int m = l + (r - l)/2;
            if (nums[m] == target) return m;
            
            if (nums[r] >= nums[m]){ // right side sorted
                if (target > nums[m] && target <= nums[r]){ // in right side, update l
                    l = m + 1;
                } else { // in left, update r
                    r = m - 1;
                }
            } else { // left side sorted, search left side (update r)
                if (target >= nums[l] && target < nums[m]){ // in left side, update r
                    r = m - 1;
                } else { // in right, update l
                    l = m + 1;
                }
            }
        }
        return -1;

    }
};

// case 1 : nums[m] is "point of rotation" - both sides sorted
//          [6, 7, (1) , 2, 3]

// case 2 : one side sorted - here check that 5 > 2
//          [6, 7, 1 , (2), 3, 4, 5]