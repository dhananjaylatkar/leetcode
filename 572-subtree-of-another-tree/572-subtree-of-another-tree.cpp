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
    bool areSame(TreeNode* root, TreeNode* subRoot)
    {
        if (root == NULL && subRoot == NULL) return true;
        if (root == NULL || subRoot == NULL) return false;
        
        if (root->val == subRoot->val)
        {
            return areSame(root->left, subRoot->left) && areSame(root->right, subRoot->right);
        }
        return false;
    }
    
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == NULL && subRoot == NULL) return true;
        if (root == NULL || subRoot == NULL) return false;
        // return areSame(root, subRoot);
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty())
        {
            TreeNode* tmp = q.front(); q.pop();
            if (tmp->val == subRoot->val)
            {
                // cout << "checking same " << subRoot->val << endl;
                if (areSame(tmp, subRoot))
                {
                    return true;
                }
            }
            if (tmp->left) q.push(tmp->left);
            if (tmp->right) q.push(tmp->right);
        }
        return false;
    }
};