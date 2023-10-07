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
    
    void backtrack(TreeNode* root, vector<vector<int>> &res, int newTarget, vector<int> &path){
        if (!root) return;
        
        path.push_back(root->val);
        newTarget -= root->val;
        
        if (newTarget == 0 && !root->left && !root->right){
            res.push_back(path);
        } else {
            backtrack(root->left, res, newTarget, path);
            backtrack(root->right, res, newTarget, path);
        }
        
        path.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> path;
        
        backtrack(root, res, targetSum, path);
        
        return res;
    }
};

/*

- start at root
- preorder traversal
- keep running sum
- if sum equal to our target and is leaf node then we push the current path into res
    - if not leaf node, exit search
- if at any point the sum is greater than what we're looking for, stop search

*/