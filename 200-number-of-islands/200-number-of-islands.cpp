class Solution {
public:
    //bfs
    vector<int> dirs = {0, 1, 0, -1 , 0};
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int islands = 0;
        for (int r = 0; r < rows; r++){
            for (int c = 0; c < cols; c++){
                if (grid[r][c] == '1'){
                    bfs(grid, r, c);
                    islands++;
                }
            }
        }
        
        return islands;
    }
    
    void bfs(vector<vector<char>>& grid, int &r, int &c){
        queue<pair<int, int>> q;
        q.push({r, c});
        grid[r][c] = 0;
        while (!q.empty()){
            int curRow = q.front().first, curCol = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++){
                int newRow = curRow + dirs[i], newCol= curCol + dirs[i + 1];
                if (newRow < 0 || newCol < 0 || newRow >= grid.size() 
                    || newCol >= grid[0].size() || grid[newRow][newCol] != '1' ) continue;
                grid[newRow][newCol] = 0;
                q.push({newRow, newCol});
            }
        }
    }
    
};