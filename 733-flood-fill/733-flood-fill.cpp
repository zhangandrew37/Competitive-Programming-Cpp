class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        //bfs
        int rows=image.size(), cols=image[0].size(), oldColor=image[sr][sc];
        if(color==oldColor) return image;
        list<vector<int>> togo; togo.push_back({sr,sc});
        int dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        while(togo.size()) {
            int r=togo.front()[0], c=togo.front()[1]; togo.pop_front();
            image[r][c]=color;
            for(auto& d:dirs) {
                int rr=r+d[0], cc=c+d[1];
                if(rr<0 || rr>=rows ||cc<0 ||cc>=cols) continue; // keep togo safe
                if(image[rr][cc]!=oldColor) continue;            // keep togo clean
                togo.push_back({rr,cc});
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