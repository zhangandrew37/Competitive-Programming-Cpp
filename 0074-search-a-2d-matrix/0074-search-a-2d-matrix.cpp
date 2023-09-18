class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rL = 0, cL = 0, cR = matrix.size() - 1, rR = matrix[0].size() - 1;
        
        // find col range ; returns cL such that cL is first one less than target
        
        while (cL < cR){
            int m = (cL + cR + 1) / 2;
            if (matrix[m][0] <= target){
                cL = m;
            } else {
                cR = m - 1;
            }
        }
    
        // find row range
        
        while (rL <= rR){
            int m = (rL + rR) / 2;
            if (matrix[cL][m] == target) return true;
            else if (matrix[cL][m] < target) rL = m + 1;
            else rR = m - 1;
        }
        
        return false;
    }
};

/*
[10,23]

*/