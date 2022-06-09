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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == NULL) return {};
        deque<TreeNode*> q;
        bool order = true;
        q.push_back(root);
        vector<vector<int>> res;
        while(!q.empty())
        {
            TreeNode* curr;
            int len = q.size();
            vector<int> tmp;
            if (order)
            {
                for (int i = 0; i<len; i++)
                {
                    curr = q.front();
                    q.pop_front();
                    tmp.push_back(curr->val);
                    if (curr->left) q.push_back(curr->left);
                    if (curr->right) q.push_back(curr->right);
                }
                
            }
            else
            {
                for (int i = 0; i<len; i++)
                {
                    curr = q.back();
                    q.pop_back();
                    tmp.push_back(curr->val);
                    if (curr->right) q.push_front(curr->right);
                    if (curr->left) q.push_front(curr->left);
                }
            }
            res.push_back(tmp);
            order = !order;
        }
        return res;
    }
};