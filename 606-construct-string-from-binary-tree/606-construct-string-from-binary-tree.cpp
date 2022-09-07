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
    string helper(TreeNode* curr)
    {
        if (curr == NULL)
        {
            return "";
        }
        if (!curr->left && !curr->right)
        {
            return to_string(curr->val);
        }
        if (!curr->right)
        {
            return to_string(curr->val) + "(" + helper(curr->left) + ")";
        }
        
        return to_string(curr->val)
            + "(" + helper(curr->left) 
            + ")(" + helper(curr->right) + ")";
    }
    
    string tree2str(TreeNode* root) {
        return helper(root);
    }
};