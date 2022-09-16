class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int m = multipliers.size();
        int n = nums.size();
        vector<vector<int>> dp = vector(m+1, vector(m+1, 0));
        
        for (int idx = m-1; idx >= 0; idx--)
        {
            for (int l = idx; l >= 0; l--)
            {
                dp[idx][l] = max(multipliers[idx]*nums[l]+dp[idx+1][l+1],
                                multipliers[idx]*nums[n-1-(idx-l)]+dp[idx+1][l]);
            }
        }
        return dp[0][0];
    }
};