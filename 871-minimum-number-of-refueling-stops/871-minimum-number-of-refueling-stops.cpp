class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int res = 0;
        int n = stations.size();
        priority_queue<int> pq;
        int i = 0;
        int max_distance = startFuel;
        while (max_distance < target)
        {
            while(i < n && stations[i][0] <= max_distance)
            {
                pq.push(stations[i][1]);
                i++;
            }
            
            if (pq.empty())
            {
                return -1;
            }
            
            max_distance += pq.top();
            pq.pop();
            res++;
        }
        
        return res;
    }
};