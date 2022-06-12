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
    TreeNode* getNextSmallestNode(TreeNode* root)
    {
        TreeNode* curr = root;
        while(curr && curr->left)
        {
            curr = curr->left;
        }
        return curr;
    }
    TreeNode* helper(TreeNode* root, int key)
    {
        if (root == NULL) return NULL;
        if (root->val > key)
        {
            root->left = helper(root->left, key);
        }
        else if (root->val < key)
        {
            root->right = helper(root->right, key);
        }
        else
        {
            if (root->left == NULL)
            {
                TreeNode* tmp = root->right;
                delete root;
                return tmp;
            }
            else if (root->right == NULL)
            {
                TreeNode* tmp = root->left;
                delete root;
                return tmp;
            }
            else
            {
                TreeNode* tmp = getNextSmallestNode(root->right);
                // Copy the value to current node and delete NextSmallestNode in right subtree
                root->val = tmp->val;
                root->right = helper(root->right, root->val);
            }
        }
        return root;
        
        
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        return helper(root, key);
    }
};