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
    int res = INT_MIN;
    
    int helper(TreeNode* curr)
    {
        if (curr == NULL) return 0;
        
        int l = max(helper(curr->left), 0);
        int r = max(helper(curr->right), 0);
        
        res = max(res, l+r+curr->val);
        
        return max(l+curr->val, r+curr->val);
    }
    int maxPathSum(TreeNode* root) {
        helper(root);
        return res;
    }
};