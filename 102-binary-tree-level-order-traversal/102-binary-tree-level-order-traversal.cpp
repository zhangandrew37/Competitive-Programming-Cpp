/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // not level order
    vector<vector<int>> res;
    
    void buildRes(TreeNode* root, int depth){
        if (!root) return;   
        if (res.size() == depth){
            res.push_back(vector<int>());
        }
        
        res[depth].push_back(root->val);
        buildRes(root->left, depth + 1);
        buildRes(root->right, depth + 1);
        
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        buildRes(root, 0);
        return res;
    }
};

/*
// bfs with queue
        if (!root) return;
        queue<int> q;
        q.add(root);
        while (!q.empty()){
            TreeNode* n = q.top();
            q.pop();
            
            if (n->left) q.push(n->left);
            if (n->right) q.push(n->right);
        }
        
        
        return {,};
*/