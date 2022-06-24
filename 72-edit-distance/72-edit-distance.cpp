class Solution {
public:
    int minDistance(string word1, string word2) {
        /*
        i -> w1 index
        j -> w2 index
        if w1[i] == w2[j]
            no-op -> i+1, j+1
        else
            1 + min(
                insert  -> i+1, j
                delete  -> i,   j+1
                replace -> i+1, j+1
            )
        
        Use 2D bottom up approach similiar to longest common subsequence
        */
        
        int m = word1.size();
        int n = word2.size();
        
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        
        for (int i = m-1; i >= 0; i--)
        {
            dp[i][n] = dp[i+1][n]+1;
        }
        for (int i = n-1; i >= 0; i--)
        {
            dp[m][i] = dp[m][i+1]+1;
        }
        
        for (int i = m-1; i >= 0; i--)
        {
            for (int j = n-1; j >= 0; j--)
            {
                if (word1[i] == word2[j])
                {
                    dp[i][j] = dp[i+1][j+1];
                }
                else
                {
                    dp[i][j] = 1 + min(dp[i][j+1], min(dp[i+1][j], dp[i+1][j+1]));
                }
            }
        }
        return dp[0][0];
    }
};