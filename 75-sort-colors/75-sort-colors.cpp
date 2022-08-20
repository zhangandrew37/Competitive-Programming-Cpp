class Solution {
public:
    void sortColors(vector<int>& nums) {
         int r = 0, w = 0, b = 0;
        
        for (int n : nums){
            if (n == 0) r++;
            if (n == 1) w++;
            if (n == 2) b++;
        }
        int i = 0;
        while(r > 0){
            nums[i++] = 0;
            r--;
        }
        
        while (w > 0){
            nums[i++] = 1;
            w--;
        }

        while (b > 0){
            nums[i++] = 2;
            b--;
        }
        
    }
};

// solution 1: store number r, w, b in array and bucket sort (not O(1) space but O(n))