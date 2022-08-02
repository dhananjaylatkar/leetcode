class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1, 1);
        
        for (int i = 2; i < n+1; i++)
        {
            int total = 0;
            for (int root = 1; root < i+1; root++)
            {
                total += dp[root-1] * dp[i-root];
            }
            dp[i] = total;
        }
        
        return dp[n];
    }
};