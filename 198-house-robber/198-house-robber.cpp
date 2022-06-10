class Solution {
public:
    
//     int helper(vector<int>& nums, int curr)
//     {
//         int n = nums.size();
//         if (curr >= n)
//         {
//             return 0;
//         }
        
//         int p1 = nums[curr] + helper(nums, curr+2);
//         int p2 = helper(nums, curr+1);
        
//         return max(p1, p2);
            
//     }
    int dp[101];
    int helper_dp(vector<int>& nums, int curr)
    {
        int n = nums.size();
        if (curr >= n)
        {
            return 0;
        }
        if (dp[curr] != -1) return dp[curr];
        
        int p1 = nums[curr] + helper_dp(nums, curr+2);
        int p2 = helper_dp(nums, curr+1);
        
        dp[curr] = max(p1, p2);
        return dp[curr];
            
    }
    int rob(vector<int>& nums) {
        // return helper(nums, 0);
        memset(dp, -1, sizeof(dp));
        return helper_dp(nums, 0);
    }
};