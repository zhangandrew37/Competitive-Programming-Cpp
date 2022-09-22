class Solution {
public:
    vector<vector<int>> adj;
    vector<bool> visited;
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        adj.resize(n);
        for (auto edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        visited.resize(n, false);
        dfs(source, destination);
        return visited[destination];
    }
    
    void dfs(int cur, int destination) {
        visited[cur] = true;
        if (cur == destination) return;
        for (auto nbr : adj[cur]){
            if (!visited[nbr]) dfs(nbr, destination);
        }
    }
};