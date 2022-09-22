class Solution {
public:
    vector<int> parent;
    
    int findParent(int node){
        return parent[node] == node ? node : (parent[node] = findParent(parent[node]));
    }
    
    void makeUnion(int u, int v){
        int pu = findParent(u);
        int pv = findParent(v);
        parent[pu] = pv;
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        parent.resize(n);
        for (int i = 0; i < n; i++){ // initially all nodes are roots
            parent[i] = i;
        } 
        
        for (auto e : edges){
            makeUnion(e[0], e[1]);
        }
        
        return findParent(source) == findParent(destination);
    }
};