class Solution {
public:
    long long int getSquares(int x, int y)
    {
        return x*x + y*y;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue <pair<long long int, pair<int, int>>> pq;
        int i = 0;
        int n = points.size();
        for (int j = 0; j < k; j++)
        {
            pq.push({getSquares(points[i][0], points[i][1]), {points[i][0], points[i][1]}});
            i++;
        }
        
        while (i < n)
        {
            long long int sq = getSquares(points[i][0], points[i][1]);
            
            if (sq < pq.top().first)
            {
                pq.pop();
                pq.push({sq, {points[i][0], points[i][1]}});
            }
            i++;
        }
        vector<vector<int>> res;
        
        while (pq.size())
        {
            res.push_back({pq.top().second.first, pq.top().second.second});
            pq.pop();
        }
        return res;
    }
};