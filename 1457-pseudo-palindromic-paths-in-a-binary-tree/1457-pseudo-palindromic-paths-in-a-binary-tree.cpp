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
    void helper (TreeNode* curr, vector<int> &count)
    {
        if (curr == NULL) return;
        
        count[curr->val]++;
        
        if (curr->left == NULL && curr->right == NULL)
        {
            // Reached leaf
            int odd = 0;
            for (int c: count)
            {
                if (c == 0) continue;
                if (c % 2 == 1) odd++;
                if (odd > 1) break;
            }
            
            if (odd == 0 || odd == 1) res++;
        }
        
        helper(curr->left, count);
        helper(curr->right, count);
        count[curr->val]--;
    }

    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> count(10, 0);
        helper(root, count);
        return res;
    }
};