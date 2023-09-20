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
    int res;
    
    int height(TreeNode* root){
        if (!root) return 0;
        int l = height(root->left);
        int r = height(root->right);
        res = max(l + r + 1, res);
        return max(l, r) + 1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        res = 0;
        if (!root) return 0;
        height(root);
        return res - 1;
    }
};