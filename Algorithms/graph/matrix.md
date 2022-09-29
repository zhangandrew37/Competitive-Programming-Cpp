# Matrix template

```c++
vector<int> dirs = {0, 1, 0, -1, 0};

vector<vector<int>> updateMatrix(vector<vector<int>>& m){
    int rows = m.size(), cols = m[0].size();
    queue<pair<int, int>> q;
    // possibly need "visited", but not always
    // pre-process queue and matrix

    while (!q.empty()){
        int curRow = q.front().first, curCol = q.front().second
        q.pop();
        for (int i = 0; i < 4; i++){
            int newRow = curRow + dirs[i], newCol = curCol + dirs[i+1];
            // check bounds and condition to just continue
            // update matrix or count
            q.emplace({newRow, new Col});
        }
    }
    
    return m;
}