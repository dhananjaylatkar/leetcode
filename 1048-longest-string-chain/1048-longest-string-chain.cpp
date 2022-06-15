class Solution {
public:
    static bool mycomp(string &s1, string &s2)
    {
        return (s1.length() < s2.length());
    }
    
    bool string_compare(string &s1, string &s2)
    {
        int n = s1.length();
        int m = s2.length();
        if (n != m+1) return false;
        
        int i = 0, j = 0;
        
        while (i < n)
        {
            if (s1[i] == s2[j])
            {
                i++;
                j++;
            }
            else
            {
                i++;
            }
        }
        
        return (i == n && j == m);
    }
    
    int longestStrChain(vector<string>& words) {
        /* Sort array based on length of strings and then apply LIS logic on words array.
        *  Prev string can be part of increasing subsequence only if it differes by one char.
        *
        * LIS:
        *     1. Create an arr to save LIS (let's call it dp).
        *     2. dp[] stores LIS up until the index. e.g. index 5 will have value of LIS of words[0]->words[5]
        *     3. Initiate dp[] with 1 since, each word in itself is a LIS.
        *     4. For words[i], LIS will be dp[j]+1 where j < i, if words[i] can be created by inserting one char in words[j].
        *     5. While updating dp[i], also update result variable which will be the final answer.
        */
        
        sort(words.begin(), words.end(), mycomp);

        int n = words.size();
        int res = 1;
        vector<int> dp(n, 1);
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (string_compare(words[i], words[j]) && dp[i] < dp[j] + 1)
                {
                    dp[i] = dp[j] + 1;
                    res = max(res, dp[i]);
                }
            }
        }
        return res;
    }
};