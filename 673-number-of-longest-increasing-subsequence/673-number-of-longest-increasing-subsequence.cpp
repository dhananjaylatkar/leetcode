class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> dp(n, 1);
        vector<int> count(n, 1);
        int maxLen = 1;
        int maxCount = 0;
    
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                {
                    
                    if (1+dp[j] > dp[i])
                    {
                        dp[i] = 1+dp[j];
                        maxLen = max(maxLen, dp[i]);
                        count[i] = count[j];
                    }
                    else if (1+dp[j] == dp[i])
                    {
                        count[i] += count[j];
                    }
                }
            }
        }
        // for (auto i: nums) cout << i << " "; cout << endl;
        // for (auto i: dp) cout << i << " "; cout << endl;
        // for (auto i: count) cout << i << " "; cout << endl;
        
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            if (dp[i] == maxLen)
            {
                res += count[i];
            }
        }
        return res;
    }
};