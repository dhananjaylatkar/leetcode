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
    int sum;
    void helper(TreeNode* root, vector<long long int> targetSum)
    {
        if (root == NULL) return;

        int n = targetSum.size();
        if (n == 0)
        {
            if (sum-root->val == 0) res++;
            targetSum = {sum-root->val, sum};
        }
        else
        {
            // cout << "Node " << root->val << endl;
            for (int i = 0; i < n; i++)
            {
                targetSum[i] -= root->val; 
                if (targetSum[i] == 0) res++;
                // cout << targetSum[i] << " ";
            }
            targetSum.push_back(sum);
            // cout << targetSum[n] << "\n";
        }
        
        helper(root->left, targetSum);
        helper(root->right, targetSum);
    }
    int pathSum(TreeNode* root, int ts) {
        if (root == NULL) return res;
        sum = ts;
        vector<long long int> targetSum = {};
        helper(root, targetSum);
        return res;
    }
};