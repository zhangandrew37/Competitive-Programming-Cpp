class Solution {
public:
    // general strategy: ignore blank cells, bfs on rotten oranges simultaneously, keep track of fresh orange count
    int orangesRotting(vector<vector<int>>& grid) {
        int mins = 0, cnt = 0, rows = grid.size(), cols = grid[0].size();
        vector<int> dirs = {-1, 0, 1, 0, -1};
        queue<pair<int, int>> q;
        
        // pre-process
        for (int r = 0; r < rows; r++){
            for (int c = 0; c < cols; c++){
                if (grid[r][c] == 1) cnt++;
                else if (grid[r][c] == 2) q.push({r,c});
            }
        }
        
                
        // bfs on all rotten simulaneously
        while (!q.empty() && cnt > 0){

            int sz = q.size();
            while (sz > 0){
                sz--;
                int r = q.front().first, c = q.front().second;
                q.pop();
                
                for (int i = 0; i < 4; i++){
                    int newR = r + dirs[i], newC = c + dirs[i+1];
                    if (newR < 0 || newC < 0 || newR >= rows || newC >= cols || grid[newR][newC] != 1) continue;

                    cnt--;
                    grid[newR][newC] = 2;
                    q.push({newR, newC});
                }
            }
            mins++;
        }
        if (cnt == 0) return mins;
        return -1;
    }
};

// [2 1 1]
// [1 1 1]
// [0 1 2]