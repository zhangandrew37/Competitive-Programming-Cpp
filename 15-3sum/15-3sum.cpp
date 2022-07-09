class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int len = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < len-2; i++){
            //sorted array, skip those behind
            if (i != 0 && nums[i] == nums[i-1]) continue;
            int target = 0 - nums[i];
            unordered_map<int, int>m;
            
            for (int j = i + 1; j < len; j++){
                int diff = target - nums[j];
                // [ 0, 0, 0, 0]
                if (m.find(diff) != m.end()){
                    while (j != i + 1 && j != len - 1 && nums[j+1] == nums[j]) j++;
                    vector<int> tmp = {nums[i], nums[j], diff};
                    res.push_back(tmp);
                }
                m.insert(pair<int, int>(nums[j], j));
            }
        }

        return res;
        
    }
};