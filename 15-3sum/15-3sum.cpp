class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // nlogn
        vector<vector<int>> res;
        int len = nums.size();
        
        for (int i = 0; i < len; i++){
            while (i != 0 && nums[i] == nums[i-1]){
                i++;
                if (i == len) return res;
            }
            int l = i + 1, r = len - 1;
            
             while (l < r){ 
                 int sum = nums[i] + nums[l] + nums[r];
                 if (sum == 0){
                     res.push_back({nums[i], nums[l], nums[r]});
                     l++;
                     while (nums[l] == nums[l-1] && l < r){
                        l++;
                    }
                 } else if (sum < 0){
                     l++;
                 } else {
                     r--;
                 }
             }
            
        }
        
        return res;
    }
};

// soln 1: hashmap (requires more space and time)
// soln 2: 2 pointers (sliding window)