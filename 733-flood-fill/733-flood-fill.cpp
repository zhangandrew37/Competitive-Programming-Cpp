class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<bool>> visited(image.size(), vector<bool>(image[0].size(), false));
        if (color != image[sr][sc]) dfs(image, visited, sr, sc, color, image[sr][sc]);
        return image;
    }
    
    void dfs(vector<vector<int>>& image, vector<vector<bool>>& visited, int sr, int sc, int newColor, int oldColor){
        // check bounds, if current color is same as orig/old, or if visited, return ("base case")
        if (sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size() || image[sr][sc] != oldColor || visited[sr][sc]) return;
        
        visited[sr][sc] = true;
        image[sr][sc] = newColor;
        dfs(image, visited, sr, sc + 1, newColor, oldColor);
        dfs(image, visited, sr, sc - 1, newColor, oldColor);
        dfs(image, visited, sr + 1, sc, newColor, oldColor);
        dfs(image, visited, sr - 1, sc, newColor, oldColor);
    }
};