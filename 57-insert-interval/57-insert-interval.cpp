class Solution {
public:
    static bool mycmp(vector<int>& a, vector<int>& b)
    {
        if (a[0] == b[0]) return a[1] < b[1];
        return a[0] < b[0];
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end(), mycmp);
        
        vector<vector<int>> res;
        
        res.push_back(intervals[0]);
        int end = intervals[0][1];
        int j = 0;
        for (int i = 1; i < intervals.size(); i++)
        {
            int start = intervals[i][0];
            
            if (start <= end)
            {
                // ovelapping
                res[j][1] = max(res[j][1], intervals[i][1]);
            }
            else
            {
                res.push_back(intervals[i]);
                j++;
            }
            end = res[j][1];
        }
        
        return res;
    }
};