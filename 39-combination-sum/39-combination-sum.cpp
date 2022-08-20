class Solution {
public:
    
    vector<vector<int>> combinations;
    
    void backtrack(vector<int>& candidates, int target, int sum, vector<int>& curCombinations, int start) {
        
        if (sum == target){
            combinations.push_back(curCombinations);
            return;
        } else if (sum > target){
            return;
        } else {
            for (int i = start; i < candidates.size(); i++){
                curCombinations.push_back(candidates[i]);
                backtrack(candidates, target, sum + candidates[i], curCombinations, i);
                curCombinations.pop_back();
            }
        }
        return;
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> cur;
        backtrack(candidates, target, 0, cur, 0);
        return combinations;
    }
};

// Notes:

// create a tree
// if any path is greater than target, then we consider that invalid
// iterative vs recursive approach (more time efficient, n^m)
// need to use backtracking to print all solution