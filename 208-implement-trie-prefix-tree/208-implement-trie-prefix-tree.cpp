class TrieNode {
public:
    TrieNode* child[26];
    bool isEnd;
    
    TrieNode() {
        for (int i = 0; i < 26; i++)
        {
            child[i] = NULL;
        }
        isEnd = false;
    }
};
class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for (char w: word)
        {
            if (curr->child[w-'a'] == NULL)
            {
                curr->child[w-'a'] = new TrieNode();
            }
            curr = curr->child[w-'a'];
        }
        curr->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for (char w: word)
        {
            if (curr->child[w-'a'] == NULL) return false;
            curr = curr->child[w-'a'];
        }
        if (curr->isEnd == false) return false;
        return true;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for (char w: prefix)
        {
            if (curr->child[w-'a'] == NULL) return false;
            curr = curr->child[w-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */