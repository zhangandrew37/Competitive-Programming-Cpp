class Solution {
public:
    
    vector<vector<int>> combinations;
    
    void backtrack(vector<int>& candidates, int target, int sum, vector<int>& curCombinations, int start) {
        
        
        for (int i = start; i < candidates.size(); i++){
            if (sum == target){
              combinations.push_back(curCombinations);
                return;  
            } else if (sum < target){
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
// backtracking (recursive, also iterates) - need to use backtracking to print all solution
// consider duplicates by passing i + 1 or i depending on solution method

// solution 1: for loop in else case, pass i 
// solution 2: everything in for loop