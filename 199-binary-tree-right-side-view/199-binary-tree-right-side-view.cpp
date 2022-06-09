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
    vector<int> rightSideView(TreeNode* root) {
        if (root == NULL) return {};
        vector<int> res;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int len = q.size();
            TreeNode* curr;
            
            
            for (int i = 0; i < len; i++)
            {
                curr  = q.front();
                q.pop();
                
                if(i == len-1) res.push_back(curr->val);
                
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
        }
        return res;
    }
};