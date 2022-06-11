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
    vector<vector<int>> res;
    
    void helper(TreeNode* root, int targetSum, vector<int> path)
    {
        if (root == NULL) return;
        
        targetSum -= root->val;
        // cout << root->val << " " << targetSum << endl;
        path.push_back(root->val);
        
        if (root->left == NULL && root->right == NULL && targetSum == 0)
        {
            res.push_back(path);
            return;
        }
        
        if (root->left) 
        {
            helper(root->left, targetSum, path);
        }
        if (root->right)
        {
            helper(root->right, targetSum, path);
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        helper(root, targetSum, path);
        return res;
    }
};