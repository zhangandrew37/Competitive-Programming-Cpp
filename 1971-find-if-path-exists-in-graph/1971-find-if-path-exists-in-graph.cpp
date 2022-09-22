class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adjLists(n, vector<int>());
        vector<bool> visited(n, false);
        
        for (auto v : edges){
            adjLists[v[0]].push_back(v[1]);
            adjLists[v[1]].push_back(v[0]);
        }
        
        queue<int> queue;
        queue.push(source);
        visited[source] = true;
        
        while (!queue.empty()){
            int cur = queue.front();
            queue.pop();
            if (cur == destination) return true;
            
            for (auto u : adjLists[cur]){
                if (!visited[u]){
                    visited[u] = true;
                    queue.push(u);
                }
            }
        }
        
        return false;
    }
};