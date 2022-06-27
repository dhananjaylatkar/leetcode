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
    int res = 0;
    int helper(TreeNode* root)
    {
        if (root == NULL) return 0;
        
        int l = 1 + helper(root->left);
        int r = 1 + helper(root->right);
        res = max(res, l+r-2);
        return max(l,r);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        helper(root);
        return res;
    }
};