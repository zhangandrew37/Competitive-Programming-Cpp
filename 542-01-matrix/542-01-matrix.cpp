class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size(), cols = mat[0].size();
        queue<pair<int, int>> queue;
        vector<int> dirs = {0, 1, 0, -1, 0};
        
        for (int r = 0; r < rows; r++){
            for (int c = 0; c < cols; c++){
                if (mat[r][c] == 0) queue.push({r,c});
                else mat[r][c] = -1;
            }
        }
        
        
        while(!queue.empty()){
            int r = queue.front().first, c = queue.front().second;
            queue.pop();
            for (int i = 0; i < 4; i++){
                int newR = r + dirs[i], newC = c + dirs[i+1];
                if (newR < 0 || newC < 0 || newR >= rows || newC >= cols || mat[newR][newC] != -1) continue;
                mat[newR][newC] = mat[r][c] + 1;
                queue.emplace(newR, newC);
            }
        }
        return mat;
    }
};