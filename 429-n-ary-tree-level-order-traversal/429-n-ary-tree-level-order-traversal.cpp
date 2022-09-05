/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        
        if (root == NULL) return res;
        
        queue<Node*> q;
        q.push(root);
        
        while (!q.empty())
        {
            int n = q.size();
            vector<int> tmp;
            for (int i = 0; i < n; i++)
            {
                Node* curr = q.front();
                q.pop();
                tmp.push_back(curr->val);
                
                for (Node* c: curr->children)
                {
                    q.push(c);
                }
            }
            res.push_back(tmp);
        }
        
        return res;
    }
};