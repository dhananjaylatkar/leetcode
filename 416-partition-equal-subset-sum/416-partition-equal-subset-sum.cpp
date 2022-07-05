class Solution {
public:
    int dp[202][20001];
    bool helper(vector<int>& nums, int sum, int idx, int curr_sum)
    {
        if (idx == nums.size())
        {
            return false;
        }
        
        if (dp[idx][sum] != -1) return dp[idx][sum];
        
        if (curr_sum == sum) 
        {
            dp[idx][sum] = true;
            return true;
        }
        
        if (curr_sum > sum)
        {
            dp[idx][sum] = false;
            return false;
        }
        
        bool p1 = helper(nums, sum-nums[idx], idx+1, curr_sum+nums[idx]);
        
        if (!p1)
        {
            dp[idx][sum] = helper(nums, sum, idx+1, curr_sum);
            return dp[idx][sum];
        }
        dp[idx][sum] = p1;
        return p1;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (int num: nums)
        {
            sum += num;
        }
        memset(dp, -1, sizeof(dp));
        return helper(nums, sum, 0, 0);
    }
};