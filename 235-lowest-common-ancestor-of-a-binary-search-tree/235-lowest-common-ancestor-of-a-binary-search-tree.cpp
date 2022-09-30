/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<TreeNode*> stackP;
        stack<TreeNode*> stackQ;
        find(root, p, stackP);
        find(root, q, stackQ);
        TreeNode* ret = nullptr;
        
        while (!stackP.empty() && !stackQ.empty()){
            if (stackP.top() != stackQ.top()) break;
            ret = stackP.top();
            stackP.pop();
            stackQ.pop();
        }
        return ret;
    }
    // l n r 
    bool find(TreeNode* root, TreeNode* n, stack<TreeNode*> &stack){
        if (!root) return false;
        if (root == n){
            stack.push(root);
            return true;
        }
        
        if (find(root->left, n, stack) || find(root->right, n, stack)){
            stack.push(root);
            return true;
        }
        
        return false;
        
    }
};