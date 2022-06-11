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
class BSTIterator {
private:
    vector<int> bst; 
    int size;
    int curr = 0;
public:
    void fill_array(TreeNode* root)
    {
        if (root == NULL) return;
        fill_array(root->left);
        bst.push_back(root->val);
        fill_array(root->right);
        
    }
    BSTIterator(TreeNode* root) {
        fill_array(root);
        size = bst.size();
    }
    
    int next() {
        return bst[curr++];
    }
    
    bool hasNext() {
        return curr < size;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */