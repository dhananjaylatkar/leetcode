class Solution {
public:
    int dp[101][101];
    bool helper(string &s1, string &s2, string &s3, int i, int j, int k)
    {
        if (dp[i][j] != -1) return dp[i][j];
        
        if(i >= s1.length() && j >= s2.length() && k >= s3.length())
        {
            return dp[i][j] = true;
        }
        
        bool p1 = false;
        
        if (i < s1.length() && k < s3.length())
        {
            if (s1[i] == s3[k])
            {
                p1 = helper(s1, s2, s3, i+1, j, k+1);
            }
        }
        if (p1) return dp[i][j] = true;
        
        if (j < s2.length() && k < s3.length())
        {
            if (s2[j] == s3[k])
            {
                p1 = helper(s1, s2, s3, i, j+1, k+1);
            }
        }
        return dp[i][j]=p1;
        
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        memset(dp, -1, sizeof(dp));
        return helper(s1, s2, s3, 0, 0, 0);
    }
};