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
    int cam = 0;
    void helper(TreeNode* root,unordered_set<TreeNode*> &visited, TreeNode* parent)
    {
        if (root == NULL)
        {
            return;
        }
        
        helper(root->left, visited, root);
        helper(root->right, visited, root);
        
        if ((parent == NULL && !visited.count(root))
           || !visited.count(root->left)
           || !visited.count(root->right))
        {
            cam++;
            visited.insert(root);
            visited.insert(root->left);
            visited.insert(root->right);
            visited.insert(parent);
        }
    }
    int minCameraCover(TreeNode* root) {
        unordered_set<TreeNode*> visited;
        visited.insert(NULL);
        helper(root, visited, NULL);
        return cam;
    }
};