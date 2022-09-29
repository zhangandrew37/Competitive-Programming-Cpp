class Solution {
public:
    vector<int> dirs = {0, 1, 0, -1 , 0};
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        int islands = 0;
        for (int r = 0; r < rows; r++){
            for (int c = 0; c < cols; c++){
                if (grid[r][c] == '1' && !visited[r][c]){
                    bfs(grid, visited, r, c);
                    islands++;
                }
            }
        }
        
        return islands;
    }
    
    void bfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int &r, int &c){
        queue<pair<int, int>> q;
        q.push({r, c});
        visited[r][c] = true;
        while (!q.empty()){
            int curRow = q.front().first, curCol = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++){
                int newRow = curRow + dirs[i], newCol= curCol + dirs[i + 1];
                if (newRow < 0 || newCol < 0 || newRow >= grid.size() 
                    || newCol >= grid[0].size() || visited[newRow][newCol] || grid[newRow][newCol] != '1' ) continue;
                visited[newRow][newCol] = true;
                q.push({newRow, newCol});
            }
        }
    }
    
};