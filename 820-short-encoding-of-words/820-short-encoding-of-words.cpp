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
    
    bool insert(string s)
    {
        TrieNode* curr = root;
        int n = s.length();
        bool isNewNode = false;
        for (int i = n-1; i >= 0; i--)
        {
            if (curr->child[s[i]-'a'] == NULL)
            {
                isNewNode = true;
                curr->child[s[i]-'a'] = new TrieNode();
            }
            curr = curr->child[s[i]-'a'];
        }
        curr->isEnd = true;
        return isNewNode;
    }
    
    static bool myCmp(string &s1, string &s2)
    {
        return s1.length() > s2.length();
    }
public:
    int minimumLengthEncoding(vector<string>& words) {
        sort(words.begin(), words.end(), myCmp);
        int res = 0;
        for (int i = 0; i < words.size(); i++)
        {
            if (insert(words[i]))
            {
                res += 1 + words[i].length();
            }
        }
        return res;
    }
};