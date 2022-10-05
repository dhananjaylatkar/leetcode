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
    void helper (TreeNode* curr, int val, int depth)
    {
        if (curr == NULL) return;
        
        if (depth == 2)
        {
            TreeNode* left = curr->left;
            curr->left = new TreeNode(val);
            curr->left->left = left;
            
            TreeNode* right = curr->right;
            curr->right = new TreeNode(val);
            curr->right->right = right;
        }
        else
        {
            helper(curr->left, val, depth-1);
            helper(curr->right, val, depth-1);
        }
        
        
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1)
        {
            TreeNode* node = new TreeNode(val);
            node->left = root;
            return node;
        }
        helper(root, val, depth);
        return root;
    }
};