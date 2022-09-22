class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        //bfs
        int rows = image.size(), cols = image[0].size(), oldColor = image[sr][sc];
        if (color == oldColor) return image;
        
        queue<vector<int>> queue; // technically just a pair
        queue.push({sr, sc});
        
        int dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        
        while (!queue.empty()){
            int curRow = queue.front()[0];
            int curCol = queue.front()[1];
            queue.pop();
            image[curRow][curCol] = color;
            for(auto d : dirs){
                int newRow = curRow + d[0];
                int newCol = curCol + d[1];
                if (newRow >= rows || newRow < 0 || newCol >= cols || newCol < 0 || 
                    image[newRow][newCol] != oldColor) continue; //bounds/diff color
                queue.push({newRow, newCol});
            }
        }
        
        return image;
        
        
    }
    
//     vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
//         if (color != image[sr][sc]) dfs(image, sr, sc, color, image[sr][sc]);
//         return image;
//     }
    
//     void dfs(vector<vector<int>>& image, int sr, int sc, int newColor, int oldColor){
//         // check bounds, if current color is same as orig/old, return ("base case")
//         if (sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size() || image[sr][sc] != oldColor) return;
        
//         image[sr][sc] = newColor;
//         dfs(image, sr, sc + 1, newColor, oldColor);
//         dfs(image, sr, sc - 1, newColor, oldColor);
//         dfs(image, sr + 1, sc, newColor, oldColor);
//         dfs(image, sr - 1, sc, newColor, oldColor);
//     }
};