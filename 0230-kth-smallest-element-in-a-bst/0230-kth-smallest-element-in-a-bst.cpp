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
    int count;
    
    void find(TreeNode* root, int k){
        if (!root) return;
        find(root->left, k);
        
        count++;
        if (count == k) {
            res = root->val;
            return;
        }
        
        find(root->right, k);
        
    }
    
    int kthSmallest(TreeNode* root, int k) {
        count = 0;
        find(root, k);
        return res;
    }
};