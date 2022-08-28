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
    int treeHeight(TreeNode* node){
        if (!node) return 0;
        return 1 + max(treeHeight(node->left), treeHeight(node->right));
    }
    
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        int left = treeHeight(root->left);
        int right = treeHeight(root->right);
        return abs(right - left) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }
};