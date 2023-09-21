class Solution {
public:
    
    int bfs(vector<vector<int>>&grid, int row, int col){
        int area = 1;
        vector<int> dirs = {0,1,0,-1,0};
        
        queue<pair<int,int>> q;
        q.push({row,col});
        grid[row][col] = 0;
        
        while (!q.empty()){
            auto [r,c] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++){
                int newR = r + dirs[i];
                int newC = c + dirs[i+1];
                if (newR < 0 || newC < 0 || newR >= grid.size() 
                    || newC >= grid[0].size() || grid[newR][newC] == 0) continue;
                area++;
                q.push({newR, newC});
                grid[newR][newC] = 0;
            }
        }
        
        return area;
    }
    

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        
        int res = 0;
        
        for (int r = 0; r < rows; r++){
            for (int c = 0; c < cols; c++){
                if (grid[r][c] == 1){
                    res = max(res, bfs(grid, r, c));
                }
            }
        }
        
        return res;
    }
};

// {i, j} {i + 1, j}, {i - 1, j}, {i + 2, j}