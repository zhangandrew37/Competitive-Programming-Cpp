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
    int dfsHeight(TreeNode* root){
        if (!root) return 0;
        int left = dfsHeight(root->left);
        int right = dfsHeight(root->right);
        if (left == -1 || right == -1 || abs(right - left) > 1) return -1; // left, right, current balanced?
        return max(left, right) + 1; // height of current node
    }
    
    bool isBalanced(TreeNode* root) {
        return dfsHeight(root) != -1;
    }
};