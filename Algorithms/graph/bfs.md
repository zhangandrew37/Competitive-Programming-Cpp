# Breadth First Search (BFS)

- n nodes
- Time: **O(V + E)**
- Data Structures: 
  - Non-recursive: Queue, sometimes Deque, HashSet
- trees are special cases of graphs 


```cpp
class Graph {
    int V; // numebr vertices
    vector< vector<int> > adj; // adjacency lists
public:
    Graph(int V); // constructor
    void addEdge(int a, int b);
    void BFS(int src);
};

// Graph g(4);
Graph::Graph(int V){
    this->V = V;
    adj.resize(V); // don't even need this maybe
}

// g.addEdge(0,1);
void Graph::addEdge(int a, int b){ //careful what a and b are
    adj[a].push_back(b);
}

// g.DFS(2);
void Graph::BFS(int src){
    vector<bool> visited(V, false);
    queue<int> queue;
    visited[src] = true;
    queue.push(src);

    while (!queue.empty()){
        int cur = queue.front();
        queue.pop();
        for (auto u : adj[cur]){
            if (!visited[u]){
                visited[u] = true;
                queue.push(u);
            }
        }
    }
}
```