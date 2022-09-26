/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public: 
    unordered_map<Node*, Node*> m; // maps old to new
    
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        return dfs(node);
    }
    
    Node* dfs(Node* node){
        if (m.find(node) != m.end()) return m[node];
        
        Node* dup = new Node(node->val);
        m[node] = dup;
        
        for (auto n : node->neighbors){
            dup->neighbors.push_back(dfs(n));
        }
        
        return dup;
    }
};