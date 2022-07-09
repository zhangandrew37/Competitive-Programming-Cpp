class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int len = nums.size();
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < len; i++){
            //sorted array, skip those behind
            if (i != 0 && nums[i] == nums[i-1]) continue;
            int target = 0 - nums[i];
            unordered_map<int, int>m;
            
            int l = i + 1, r = len - 1;
            
            while (l < r){
                int sum = nums[i] + nums[l] + nums[r];
                if (sum > 0){
                    r --;
                } else if (sum < 0){
                    l++;
                } else {
                    vector<int> triplet = {nums[i], nums[l], nums[r]};
                    res.push_back(triplet);
                    l++;
                    // skip duplicates
                    while (nums[l] == nums[l - 1] && l < r) {
                        l++;
                    }
                }
            
        }
        }

        return res;
        
    }
};