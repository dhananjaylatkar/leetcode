class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) { 
        vector<string> res;
        
        for (string word: words)
        {
            unordered_map<char, char> m;
            unordered_map<char, char> m_rev;
            bool found = true;
            for (int i = 0; i < word.length(); i++)
            {
                if (m.find(word[i]) != m.end())
                {
                    // found in map
                    if (m[word[i]] != pattern[i]) 
                    {
                        found = false;
                        break;
                    }
                }
                else if (m_rev.find(pattern[i]) != m_rev.end())
                {
                    // found in map_rev
                    if (m_rev[pattern[i]] != word[i])
                    {
                        found = false;
                        break;
                    }
                }
                else
                {
                    m[word[i]] = pattern[i];
                    m_rev[pattern[i]] = word[i];
                }
            }
            
            if (found)
            {
                res.push_back(word);
            }
        }
        return res;
    }
};