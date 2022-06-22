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
    int res;
    void helper(TreeNode* root, int k, int &count)
    {
        if (root != NULL)
        {
            helper(root->left, k, count);
            count++;
            if (count == k)
            {
                res = root->val;
                return;
            }
            if (count > k) return;
            helper(root->right, k, count);
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        res = -1;
        int count  = 0;
        helper(root, k, count);
        return res;
    }
};