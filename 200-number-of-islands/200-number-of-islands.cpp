class Solution {
public:
    vector<int> dirs = {0, 1, 0, -1 , 0};
    
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int islands = 0;
        for (int r = 0; r < rows; r++){
            for (int c = 0; c < cols; c++){
                if (grid[r][c] == '1'){
                    islands++;
                    eraseIslands(grid, r, c);
                }
            }
        }
        
        return islands;
    }
    
    void eraseIslands(vector<vector<char>>&grid, int i, int j){
        int m = grid.size(), n = grid[0].size();
        if (i < 0 || i == m || j < 0 || j == n || grid[i][j] == '0') {
            return;
        }
        grid[i][j] = '0';
        eraseIslands(grid, i - 1, j);
        eraseIslands(grid, i + 1, j);
        eraseIslands(grid, i, j - 1);
        eraseIslands(grid, i, j + 1);
    }
};