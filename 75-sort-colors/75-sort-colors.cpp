class Solution {
public:
    void sortColors(vector<int>& nums) {
         vector<int> bucket {0,0,0};
        
        for (int n : nums){
            if (n == 0) bucket[0]++;
            if (n == 1) bucket[1]++;
            if (n == 2) bucket[2]++;
        }
        int i = 0;
        while(bucket[0] > 0){
            nums[i++] = 0;
            bucket[0]--;
        }
        
        while (bucket[1] > 0){
            nums[i++] = 1;
            bucket[1]--;
        }

        while (bucket[2] > 0){
            nums[i++] = 2;
            bucket[2]--;
        }
        
    }
};

// solution 1: store number r, w, b in array and bucket sort (not O(1) space but O(n))