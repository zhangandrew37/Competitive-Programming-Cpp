class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> res;

        for (int i = 0; i < nums.size(); i++){
            int diff = target - nums[i];
            if (m.find(diff) != m.end()){
                res.push_back(i);
                res.push_back(m.at(diff));
                break;
            }
            m.insert(pair<int, int>(nums[i], i));
        }
        return res;
    }
};