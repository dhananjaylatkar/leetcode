class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        
        vector<int> dp(n, 0);
        priority_queue<pair<int, int>> pq;
        
        dp[n-1] = nums[n-1];
        pq.push({dp[n-1], n-1});
        
        for (int i = n-2; i >= 0; i--)
        {
            while(pq.top().second > i+k)
            {
                pq.pop();
            }
            
            dp[i] = nums[i] + pq.top().first;
            pq.push({dp[i], i});
        }
        
        return dp[0];
    }
};