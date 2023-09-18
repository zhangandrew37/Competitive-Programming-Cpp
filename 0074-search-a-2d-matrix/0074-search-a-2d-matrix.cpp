class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rL = 0, cL = 0, rR = matrix.size() - 1, cR = matrix[0].size() - 1;
        
        // find row range ; returns rL such that rL is first one less than target
        
        while (rL < rR){
            int m = (rL + rR + 1) / 2;
            if (matrix[m][0] <= target){
                rL = m;
            } else {
                rR = m - 1;
            }
        }
    
        // find col range
        
        while (cL <= cR){
            int m = (cL + cR) / 2;
            if (matrix[rL][m] == target) return true;
            else if (matrix[rL][m] < target) cL = m + 1;
            else cR = m - 1;
        }
        
        return false;
    }
};

/*
[10,23]

*/