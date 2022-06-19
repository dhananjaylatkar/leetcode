class TrieNode {
public:

    bool isEnd;
    TrieNode* child[26];

    TrieNode() {
        isEnd = false;
        for (int i = 0; i < 26; i++)
        {
            child[i] = NULL;
        }
    }
};

class Solution {
private:
    TrieNode* root = new TrieNode();
    void insert (string &s)
    {
        TrieNode* curr = root;
        
        for (int i = 0; i < s.length(); i++)
        {
            int idx = s[i] - 'a';
            
            if (curr->child[idx] == NULL)
            {
                curr->child[idx] = new TrieNode();
            }
            curr = curr->child[idx];
        }
        curr->isEnd = true;
    }
    void getNWords(TrieNode* root, int &n, string &path, vector<string> &res)
    {
        if (root == NULL || n <= 0) return;
        
        if (root->isEnd)
        {
            res.push_back(path);
            n--;
        }
        
        for (int i = 0; i < 26; i++)
        {
            if (root->child[i])
            {
                path.push_back(i + 'a');
                getNWords(root->child[i], n, path, res);
                path.pop_back();
            }
        }
    }
    vector<string> findAllPrefix (string &s)
    {
        TrieNode* curr = root;
        vector<string> res;
        for (int i = 0; i < s.length(); i++)
        {
            int idx = s[i] - 'a';
            
            if (curr->child[idx] == NULL)
            {
                return res;
            }
            curr = curr->child[idx];
        }
        int n = 3;
        getNWords(curr, n, s, res);
        return res;
    }
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        for (int i = 0; i < products.size(); i++)
        {
            insert(products[i]);
        }
        vector<vector<string>> res;
        for (int i = 1; i < searchWord.length()+1; i++)
        {
            string tmp = searchWord.substr(0, i);
            vector<string> words = findAllPrefix(tmp);
            // cout << tmp << endl;
            res.push_back(words);
        }
        return res;
    }
};