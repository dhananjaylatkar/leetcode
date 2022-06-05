/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL) return root;
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int q_len = q.size();
            Node* prev = NULL;
            for (int i = 0; i < q_len; i++)
            {
                Node* tmp = q.front();
                q.pop();
                
                tmp->next = prev;
                prev = tmp;
                
                if (tmp->right) q.push(tmp->right);
                if (tmp->left) q.push(tmp->left);
            }
        }
        
        return root;
    }
};