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
    map<int, vector<vector<int>>> m;
    
    void helper(TreeNode* curr, int row, int col)
    {
        if (curr == NULL) return;
        
        if (m.find(col) != m.end())
        {
            m[col].push_back({curr->val, row});
        }
        else
        {
            m[col] = {{curr->val, row}};
        }
        
        helper(curr->left, row+1, col-1);
        helper(curr->right, row+1, col+1);
    }

    static bool mycmp (vector<int> &a, vector<int> &b) {
        if (a[1] == b[1])
        {
            return a[0] < b[0];
        }
        return a[1] < b[1];
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        helper(root, 0, 0);
        
        vector<vector<int>> res;
        for (auto it: m)
        {
            sort(it.second.begin(), it.second.end(), mycmp);
            vector<int> tmp;
            for (vector<int> v: it.second)
            {
                tmp.push_back(v[0]);   
            }
            res.push_back(tmp);
        }
        return res;
    }
};