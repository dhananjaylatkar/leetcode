class TrieNode {
public:
    bool isEnd;
    TrieNode* children[27];
    int index;
    TrieNode()
    {
        isEnd = false;
        index = -1;
        for (int i = 0; i < 27; i++)
        {
            children[i] = NULL;
        }
    } 
};
class WordFilter {
private:
    TrieNode* root = new TrieNode();
    void insert(string &s, int index)
    {
        TrieNode* curr = root;
        for (int i = 0; i < s.length(); i++)
        {
            int idx = s[i] - 'a';
            if (idx == '#' - 'a') idx = 26;
            
            if (!curr->children[idx])
            {
                curr->children[idx] = new TrieNode();
            }
            
            curr = curr->children[idx];
        }
        curr->isEnd = true;
        curr->index = index;
    }
    
    void getMaxIndex(TrieNode* root, int &res)
    {
        if (root == NULL) return;
        if (root->isEnd)
        {
            res = max(res, root->index);
            // cout << res << endl;
            return;
        }
        TrieNode* curr = root;

        for (int i = 0; i < 27; i++)
        {
            if (root->children[i])
            {
                getMaxIndex(root->children[i], res);
            }
        }
    }
    
    int searchPrefix (string &s)
    {
        TrieNode* curr = root;
        // cout << "Searching " << s << endl;
        for (int i = 0; i < s.length(); i++)
        {
            int idx = s[i] - 'a';
            if (idx == '#' - 'a') idx = 26;
            // cout << "[" << s[i] << ", " << idx << "]\n";
            if (!curr->children[idx]) return -1;
            curr = curr->children[idx];
        }
        int res = -1;
        getMaxIndex(curr, res);
        return res;
    }
    
    void insertAllVariations(string &s, int index)
    {
        string _s = s+"#"+s;
        
        for (int i = 0; i < s.length(); i++)
        {
            string tmp = _s.substr(i, _s.length()-i);
            // cout << "Inserting " << tmp << endl;
            insert(tmp, index);
        }
    }
public:
    
    WordFilter(vector<string>& words) {
        for (int i = 0; i < words.size(); i++)
        {
            insertAllVariations(words[i], i);
        }
    }
    
    int f(string prefix, string suffix) {
        string _s = suffix+"#"+prefix;
        return searchPrefix(_s); 
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */