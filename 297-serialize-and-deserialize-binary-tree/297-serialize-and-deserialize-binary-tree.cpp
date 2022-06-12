/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
private:
    vector<int> create_array(string s)
    {
        vector<int> res;
        int n = s.length();
        int i = 0;
        
        while (i < n)
        {
            int end = s.find(' ', i);
            string tmp = s.substr(i, end-i);
            if (tmp == "#")
            {
                res.push_back(INT_MIN);
            }
            else
            {
                res.push_back(stoi(tmp));
            }
            i = end+1;
        }
        return res;
    }
    int idx = 0;
    TreeNode* create_tree(vector<int> &pre)
    {
        if (idx >= pre.size()) return NULL;
        if (pre[idx] == INT_MIN) return NULL;
        
        TreeNode* root = new TreeNode(pre[idx]);
        idx++;
        root->left = create_tree(pre);
        idx++;
        root->right = create_tree(pre);
        
        return root;
    }
    void preorder(TreeNode* root, string &path)
    {
        if (root == NULL) 
        {
            path += "# ";
            return;
        }
        
        path += to_string(root->val) + " ";
        
        preorder(root->left, path);
        
        preorder(root->right, path);
        
    }
public:
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string path = "";
        preorder(root, path);
        // cout << path << endl;
        return path;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<int> in_arr = create_array(data);
        // for (int i: in_arr) cout << i << " ";
        idx = 0;
        
        return create_tree(in_arr);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));