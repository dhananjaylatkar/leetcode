class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<vector<int>> engineers;
        
        for (int i = 0; i < n; i++)
        {
            engineers.push_back({efficiency[i], speed[i]});
        }
        sort(engineers.rbegin(), engineers.rend());
        
        priority_queue<int> pq;
        long long int speed_sum = 0;
        long long int res = INT_MIN;
        
        for (int i = 0; i < n; i++)
        {
            vector<int> curr = engineers[i];
            speed_sum += curr[1];
            pq.push(-curr[1]);
            
            if (pq.size() > k)
            {
                speed_sum += pq.top();
                pq.pop();
            }
            
            res = max(res, speed_sum*curr[0]);
        }
        
        return res%1000000007;
    }
};