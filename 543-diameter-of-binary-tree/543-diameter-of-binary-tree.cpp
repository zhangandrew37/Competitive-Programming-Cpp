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
    int depth(TreeNode* root, int &curMax){
        if (!root) return 0;
        int l = depth(root->left, curMax);
        int r = depth(root->right, curMax);
        curMax = max(curMax, l + r);
        return max(l, r) + 1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int curMax = 0;
        depth(root, curMax);
        return curMax;
    }
};