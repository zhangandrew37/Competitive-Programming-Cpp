# Depth First Search (DFS)

- n nodes
- Time: **O(V + E)**
- Data Structures: 
  - Recursive: HashSet (to detect cycle)
  - Non-recursive: HashSet, Stack
- trees are special cases of graphs 

dfsPrint: recursive

```cpp
class Graph {
    int V; // numebr vertices
    vector<vector<int>> adj; // adjacency lists
    vector<bool> visited;

public:
    Graph(int V); // constructor
    void addEdge(int a, int b);
    void DFS(int src);
}

// Graph g(4);
Graph::Graph(int V){
    this->V = V;
    for (int i = 0; i < V; i++){
        adj.push_back(vector<int>());
        visited.push_back(false);
    }
}

// g.addEdge(0,1);
void Graph::addEdge(int a, int b){ //careful what a and b are
    adj[a].push_back(b);
}

// g.DFS(2);
void Graph::DFS(int src){
    visited[src] = true;

    for (auto u : adj[src]){
        if (!visited[u]){
            DFS(u);
        }
    }
}
```

non-recursive (with stack)

```cpp
class Graph {
    int V; // numebr vertices
    vector<vector<int>> adj; // adjacency lists
public:
    Graph(int V); // constructor
    void addEdge(int a, int b);
    void DFS(int src);
}

// Graph g(4);
Graph::Graph(int V){
    this->V = V;
    for (int i = 0; i < V; i++){
        adj.push_back(vector<int>());
    }
}

// g.addEdge(0,1);
void Graph::addEdge(int a, int b){ //careful what a and b are
    adj[a].push_back(b);
}

// g.DFS(2);
void Graph::DFS(int src){
    vector<bool> visited(V, false);
    stack<int> stack;
    stack.push(src);

    while (!stack.empty()){
        int cur = stack.top();
        stack.pop();
        if (!visited[cur]) visited[cur] = true;

        for (auto u : adj[cur]){
            if (!visited[u]) stack.push(u);
        }
    }
}
```
