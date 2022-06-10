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
    int pre_idx = 0;
    unordered_map<int, int> in_idxs;
    TreeNode* helper(vector<int> &preorder, int in_left, int in_right)
    {
        if (in_left > in_right) return NULL;
        
        // Create new root using preorder
        int root_val = preorder[pre_idx];
        pre_idx++;
        TreeNode* root = new TreeNode(root_val);
        
        // Create left and right subtrees recursively.
        root->left = helper(preorder, in_left, in_idxs[root_val]-1);
        root->right = helper(preorder, in_idxs[root_val]+1, in_right);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++)
        {
            in_idxs[inorder[i]] = i;
        }
        
        return helper(preorder, 0, inorder.size()-1);
    }
};