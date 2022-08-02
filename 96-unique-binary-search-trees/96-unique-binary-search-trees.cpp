class Solution {
public:
    int numTrees(int n) {
        /*
            [1, 2,3,4]  root = 1
            [1, 2, 3,4] root = 2
            [1,2, 3, 4] root = 3
            [1,2,3, 4]  root = 4
            
            We find number of trees possible for all roots.
            Base condition = 0 => 1 and 1 => 1
        */
        
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