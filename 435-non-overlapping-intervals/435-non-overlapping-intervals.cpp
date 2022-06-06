class Solution {
public:
    static bool mycmp(vector<int> &a, vector<int> &b)
    {
        if (a[0] == b[0]) return a[1] < b[1];
        return a[0] < b[0];
    }
    
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), mycmp);
        // for (auto it: intervals) cout << "[" << it[0] << ", " << it[1] << "] "; cout << endl;
        int res = 0;
        int prevEnd = intervals[0][1];
        
        for (int i = 1; i < intervals.size(); i++)
        {
            if (prevEnd > intervals[i][0])
            {
                // Overlapping
                res++;
                prevEnd = min(prevEnd, intervals[i][1]); // Keep the smaller interval i.e. remove larger interval
            }
            else
            {
                // Not Overlapping
                prevEnd = intervals[i][1]; // Move to next interval
            }
            
        }
        return res;
    }
};