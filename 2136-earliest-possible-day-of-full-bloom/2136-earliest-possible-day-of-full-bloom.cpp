class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        priority_queue<pair<int, int>> pq;
        int n = plantTime.size();
        for (int i = 0; i < n; i++)
        {
            pq.push({growTime[i], plantTime[i]});
        }
        
        int res = 0;
        int curr_day = 0;
        
        while (pq.size())
        {
            curr_day += pq.top().second;
            
            res = max(res, curr_day + pq.top().first);
            
            pq.pop();
        }
        
        return res;
    }
};