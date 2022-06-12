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
        if (root == NULL) return NULL;
        
        if (root == p || root == q)
        {
            return root;
        }
        
        TreeNode* lca1 = lowestCommonAncestor(root->left, p, q);
        TreeNode* lca2 = lowestCommonAncestor(root->right, p, q);
        
        if (lca1 && lca2) return root; // Found p,q in curr subtree
        
        if (lca1)
        {
            return lca1;
        }
        else
        {
            return lca2;
        }
        return NULL; // Should not reach here
    }
};