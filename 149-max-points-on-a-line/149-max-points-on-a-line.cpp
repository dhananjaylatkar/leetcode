class Solution {
public:
    double getSlope(vector<int> &a, vector<int> &b)
    {
        if (a[1] == b[1]) return INT_MAX;
        return ((float)(a[0]-b[0])/((float)a[1]-b[1])) *1e5;
    }
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            unordered_map<double, int> m;
            for (int j = 0; j < n; j++)
            {
                if (i==j) continue;
                double slope = (float) (points[i][1]-points[j][1]) / (float) (points[i][0] - points[j][0])*1e4;
                // cout << slope << endl;
                m[slope]++;
                res = max(res, m[slope]);
            }
            
        }
        return res+1;
    }
};