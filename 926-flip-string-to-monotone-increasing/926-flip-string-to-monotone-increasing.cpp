class Solution {
public:
    int dp[100001][2]; // idx,prev
    int helper(string &s, int idx, int prev)
    {
        if (idx == s.length()) return 0;
        
        if (dp[idx][prev] != -1) return dp[idx][prev];
        
        int p1 = INT_MAX;
        int p2 = INT_MAX;
        
        if (s[idx] == '0' and prev == 0)
        {
            p1 = helper(s, idx+1, 0); // don't flip
            p2 = 1 + helper(s, idx+1, 1); // flip
        }
        else if (s[idx] == '0' and prev == 1)
        {
            p2 = 1 + helper(s, idx+1, 1); // flip
        }
        else if (s[idx] == '1' and prev == 0)
        {
            p1 = helper(s, idx+1, 1); // don't flip
            p2 = 1 + helper(s, idx+1, 0); // flip
        }
        else if (s[idx] == '1' and prev == 1)
        {
            p1 = helper(s, idx+1, 1);
        }
        return dp[idx][prev]=min(p1, p2);
    }
    int minFlipsMonoIncr(string s) {
        memset(dp, -1, sizeof(dp));
        return helper(s, 0, 0);
    }
};