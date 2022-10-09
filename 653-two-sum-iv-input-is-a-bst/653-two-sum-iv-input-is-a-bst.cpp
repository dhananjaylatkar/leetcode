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
    bool helper (TreeNode* curr, int k, unordered_set<int> &s)
    {
        if (curr == NULL) return false;
        
        if (s.find(k-curr->val) != s.end()) return true;
        
        s.insert(curr->val);
        
        return helper(curr->left, k, s) 
            || helper(curr->right, k, s);
    }
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> s;
        return helper(root, k, s);
    }
};