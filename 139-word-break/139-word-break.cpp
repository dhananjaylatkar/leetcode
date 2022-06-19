class Solution {
public:
    unordered_map<int, bool> m;
    bool helper(string &s, vector<string>& wordDict, int len)
    {
        if (m.count(len))
        {
            return m[len];
        }
        if (s.length() == len)
        {
            m[len] = true;
            return true;
        }

        if (s.length() < len)
        {
            m[len] = false;
            return false;
        }
        
        for (int i = 0; i < wordDict.size(); i++)
        {
            int w_l = wordDict[i].length();
            if (s.substr(len, w_l) == wordDict[i])
            {
                if (helper(s, wordDict, len+w_l))
                {
                    m[len] = true;
                    return true;
                }
            }
        }
        m[len] = false;
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        return helper(s, wordDict, 0);
    }
};