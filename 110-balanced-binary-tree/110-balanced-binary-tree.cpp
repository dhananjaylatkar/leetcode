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
    bool bal = true;
    int height(TreeNode* root)
    {
        if (root == NULL || !bal)
        {
            return 0;
        }
        int l = 1 + height(root->left);
        int r = 1 + height(root->right);
        if (abs(l-r) > 1)
        {
            bal = false;
            return 0;
        }
        return max(l, r);
    }
    bool isBalanced(TreeNode* root) {
        height(root);
        return bal;
    }
};