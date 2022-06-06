class Solution {
public:
    static bool mycomp(vector<int> &a, vector<int> &b)
    {
        if (a[0] == b[0]) return a[1] < b[1];
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), mycomp);
        
        vector<vector<int>> res;
        int n = intervals.size();
        res.push_back(intervals[0]);
        int j = 0;
        for (int i = 1; i < intervals.size(); i++)
        {
            if (res[j][1] >= intervals[i][0])
            {
                // res[j][0] = res[j][0];
                res[j][1] = max(res[j][1], intervals[i][1]);
            }
            else
            {
                j++;
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};