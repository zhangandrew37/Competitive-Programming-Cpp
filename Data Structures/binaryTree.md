# Binary Tree

- Binary Search Tree (BST) is sorted

Types:
- **Full Tree**
  - nodes have either 0 (leaves) or 2 children
- **Complete Tree**
  - nodes are completely filled except last level
  - on last level: nodes added from the left (also in general)
- **Perfect Tree**
  - all nodes have 2 children and all leaf nodes are a the same level

Traversals:

- Preorder (node/root, l, r)
  - Copy of the tree
  - Prefix/polish expression ( + 3 4)
- Inorder (l, node/root, r)
  - Non-decreasing order (can reverse traversal for non-increasing)
- Postorder (l, r, node/root)
  - delete the tree
  - postfix (reverse polish) expression ( 3 4 + )

Solving binary tree problems

General algorithm:
- recursive

```
1. find base case
2. call same function on left subtree
3. call same function on right subtree
4. join the results
```

ex. check if element exists in tree

```cpp
bool exists(root, value){
    if (!root) return false;
    inLeft = exists(root->left, value);
    inRight = exists(root->right, value);
    return root->data == value || inLeft || inRight;
}
```

### BFS
O(n) time O(n) space

```
while (queue isn't empty)
- have current element and queue of elements
- add current to list of values
- add next element (from children) to back of queue
- front of queue is now current
```


### DFS
- preorder, inorder, postorder
  
O(n) time O(n) space

```
while (stack is not empty)
- similar to BFS but using stack
- need to check if child exists before adding to stack
```

```cpp
stack<int> stack; // stack<TreeNode*> stack
stack.push(root);
vector<int> result;

while (!stack.empty()){
    int cur = stack.top();
    stack.pop();

    // do something with current value
    result.push_back(cur->val);

    // left first:
    if (cur->right) stack.push(cur->right);
    if (cur->left) stack.push(cur->left);
}
```

### BFS

```cpp
vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()){
            int n = q.size();
            vector<int> cur;
            
            for (int i = 0; i < n; i++){
                TreeNode *p = q.front();
                q.pop();
                cur.push_back(p->val);

                // left to right (if we want right to left, swap lines)
                if (p->left) q.push(p->left);
                if (p->right) q.push(p->right);
            }
            
            res.push_back(cur);
            
        }
        
        
        return res;
    }
```

### Path

```cpp
unordered_set<int> pSet;
    
    bool searchP(TreeNode* root, TreeNode* p){
        if (!root) return false;
        
        pSet.insert(root->val);
        
        if (root->val == p->val){
            return true;
        }
        if (searchP(root->left, p) || searchP(root->right, p)) return true;
        
        pSet.erase(root->val);
        return false;
    }
    ```