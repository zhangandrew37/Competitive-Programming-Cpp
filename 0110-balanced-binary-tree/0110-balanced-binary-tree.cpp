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
    bool res;
    
    int depth(TreeNode* root){
        if (!root) return 0;
        int left = depth(root->left);
        int right = depth(root->right);
        if (abs(left - right) > 1) res = false;
        return max(left, right) + 1;
    }
    
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        res = true;
        depth(root);
        return res;
    }
};