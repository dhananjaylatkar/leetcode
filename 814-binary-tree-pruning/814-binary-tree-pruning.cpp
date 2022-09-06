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
    TreeNode* helper(TreeNode* curr)
    {
        if (curr == NULL)
        {
            return NULL;
        }
        curr->left = helper(curr->left);
        curr->right = helper(curr->right);
        
        if (curr->val == 0 && curr->left == NULL && curr->right == NULL)
        {
            // cout << "deleting...\n";
            curr = NULL;
        }
        
        return curr;
    }
    TreeNode* pruneTree(TreeNode* root) {
        return helper(root);
    }
};