class Solution {
public: 
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int, int> m;
        vector<int> _nums;
        for (int i = 0; i < nums.size(); i++)
        {
            if (m.find(nums[i]) == m.end()) _nums.push_back(nums[i]);
            m[nums[i]]++;
        }
        
        sort(_nums.begin(), _nums.end());
        int n = _nums.size();
        
        vector<int> dp(n, 0);
        dp[0] = m[_nums[0]] * _nums[0];
        for (int i = 1; i < n; i++)
        {
            dp[i] = m[_nums[i]] * _nums[i];
            if (_nums[i-1] != _nums[i]-1)
            {
                dp[i] += dp[i-1];
            }
            else
            {
                if (i-2 >= 0)
                {
                    dp[i] = max(dp[i]+dp[i-2], dp[i-1]);
                }
                else
                {
                    dp[i] = max(dp[i], dp[i-1]);
                }
            }
        }
        
        return dp[n-1];
    }
};