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
    unordered_set<int> pSet;
    stack<TreeNode*> qStack;
    
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
    
    bool searchQ(TreeNode* root, TreeNode* q){
        if (!root) return false;
        
        qStack.push(root);
        
        if (root->val == q->val){
            return true;
        }
        if (searchQ(root->left, q) || searchQ(root->right, q)) return true;
        
        qStack.pop();
        return false;
    }
    
    
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans;
        // find p, add to unordered set
        searchP(root, p);
        // find q, add to stack
        searchQ(root, q);
        // (while) loop through stack
        for (auto c: pSet){
            cout << c;
        }
        while (!qStack.empty()){
            if (pSet.find(qStack.top()->val) != pSet.end()){
                return qStack.top(); 
            } 
            qStack.pop();
        }
        return ans;
    }
};