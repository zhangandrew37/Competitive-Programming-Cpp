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
            int target = 0 - nums[i];
            unordered_set<int> prevNums;
            for (int j = i+1; j < len; j++){
                
                int diff = target - nums[j];
                if (prevNums.find(diff) != prevNums.end()){
                    vector<int> triplet{nums[i], nums[j], diff};
                    res.push_back(triplet);
                    while (j < len -1 && nums[j+1] == nums[j]) j++;
                }
                prevNums.insert(nums[j]);
            }
        }
        
        return res;
        
        
    }
};