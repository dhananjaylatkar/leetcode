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
    void helper(TreeNode* root, int max_till_now)
    {
        if (root == NULL)
        {
            return;
        }
        
        if (root->val >= max_till_now)
        {
            res++;
        }
        max_till_now = max(max_till_now, root->val);

        helper(root->left, max_till_now);
        helper(root->right, max_till_now);
    }
    int goodNodes(TreeNode* root) {
        helper(root, root->val);
        return res;
    }
};