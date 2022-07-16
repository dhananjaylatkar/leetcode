class Solution {
public:
    int dp[101];
    int helper(vector<int>& nums, int idx)
    {
        int n = nums.size();
        if (idx >= n) return 0;
        if (dp[idx] != -1) return dp[idx];
        int p1 = nums[idx] + helper(nums, idx+2);
        int p2 = helper(nums, idx+1);
        return dp[idx] = max(p1, p2);
    }
    int rob(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        
        return helper(nums, 0);
    }
};