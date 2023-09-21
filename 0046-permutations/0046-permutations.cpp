class Solution {
public:
    void backtrack(vector<vector<int>> &res, vector<int> &cur, unordered_set<int> &set, vector<int>& nums){
        if (cur.size() == nums.size()) {
            res.push_back(cur);
            return;
        }
        
        for (int i = 0; i < nums.size(); i++){
            if (set.find(i) != set.end()) continue;
            set.insert(i);
            cur.push_back(nums[i]);
            backtrack(res, cur, set, nums);
            cur.pop_back();
            set.erase(i);
        }
        
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        unordered_set<int> set;
        backtrack(res, cur, set, nums);
        return res;
    }
};