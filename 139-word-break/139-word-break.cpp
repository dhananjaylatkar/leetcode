class Solution {
public:
    int dp[301];
    bool helper(string s, int idx, vector<string>& wordDict)
    {
        int n = s.length();
        
        if (idx == n)
        {
            return true;
        }
        
        if (dp[idx] != -1) return dp[idx];
        
        bool res = false;
        
        for (string word: wordDict)
        {
            int s_i = idx;
            int i = 0;
            bool is_word_present = true;
            while (i < word.length() && s_i < n)
            {
                if (word[i] != s[s_i])
                {
                    is_word_present = false;
                    break;
                }
                i++;
                s_i++;
            }
            
            if (i == word.length() && is_word_present)
            {
                res |= helper(s, s_i, wordDict);
                if (res)
                {
                    return dp[idx] = true;
                }
            }
        }
        
        return dp[idx] = res;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        memset(dp, -1, sizeof(dp));
        return helper(s, 0, wordDict);
    }
};