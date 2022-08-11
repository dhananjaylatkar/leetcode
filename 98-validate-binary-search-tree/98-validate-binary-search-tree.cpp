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
    bool valid = true;
    void helper(TreeNode* root, long int low, long int high) {
        if (root == NULL)
        {
            return;
        }
        
        if (!valid) return;
        
        if (root->val <= low || root->val >= high)
        {
            valid = false;
            return;
        }
        if (root->left)
        {
            if (root->left->val > root->val)
            {
                valid = false;
                return;
            }
            helper(root->left, low, root->val);
        }
        if (root->right)
        {
            if (root->right->val < root->val)
            {
                valid = false;
                return;
            }
            helper(root->right, root->val, high);
        }
    }
    bool isValidBST(TreeNode* root) {
        helper(root, -2147483649, 2147483648);
        return valid;
    }
};