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
    TreeNode* construct(vector<int>& preorder, unordered_map<int, int> &m, int a, int b, int c, int d){
        TreeNode* n = new TreeNode(preorder[a]);
        if (a==b) return n;
        
        int left = preorder[a+1];
        int idx = m[left];
        int len = idx - c + 1;
        
        // construct left subtree
        n->left = construct(preorder, m, a + 1, a + len, c, c + len - 1);
        
        // check if there's no right subtree
        if (idx + 1 == d) return n;
        
        // construct right subtree
        n->right = construct(preorder, m, a + len + 1, b, idx + 1, d -1);
        return n;
    }
        
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        unordered_map<int, int> m; // node value -> index in postorder array
        int len = postorder.size();
        for (int i = 0; i < len; i++) m[postorder[i]] = i;
        return construct(preorder, m, 0, len - 1, 0, len - 1);
    }
};

/*

map: <value, postIndex>

construct(a,b,c,d)
- pre [a,b], post [c,d]

- root is the first element of pre, say at index a
    - this is the root of our current tree we're building
- to build left side
    - root of our left subtree is at index a + 1
    - search map for the postIndex of that left root
    - construct()
    - 
- break 

pre:  [root][.. left ...][... right ...]
post: [.. left ...][... right ...][root]

pre:  [1,2,4,5,3,6,7]
-> a = 1, b = 3
-> a = a + 1, b = b + d - c
post: [4,5,2,6,7,3,1]
-> c = 0, d = 2
-> c = c, d = map[left root value]

pre: [2,4,5]
post:[4,5,2]

pre: [3,6,7]
post:[6,7,3]

     1
        \
        3
       / \
      6.   7
      
     1
    /
   3
  /. \
 6    7
   
pre: [1,3,6,7]
post: [6,7,3,1]
*/