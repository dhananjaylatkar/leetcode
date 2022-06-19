class Solution {
public:
    int dp[101];
    int helper(string &s, int idx)
    {
        if (idx == s.length())
        {
            dp[idx] = 1;
            return 1;
        }
        if (idx > s.length()) return 0;
        
        if (dp[idx] != -1) return dp[idx];
        
        int p1 = 0;
        int p2 = 0;
        
        if (s[idx] != '0')
        {
            p1 = helper(s, idx+1);
        }
        int curr = stoi(s.substr(idx, 2));

        if (curr > 9 && curr < 27)
        {
            p2 = helper(s, idx+2);
        }
        dp[idx] = p1+p2;
        return dp[idx];
    }
    int numDecodings(string s) {
        memset(dp, -1, sizeof(dp));
        return helper(s, 0);
    }
};