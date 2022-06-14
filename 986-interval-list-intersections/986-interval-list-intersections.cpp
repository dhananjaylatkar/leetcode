class Solution {
public:
    bool overlapping(vector<int> a, vector<int> b)
    {
        if ((b[0] <= a[0] && a[0] <= b[1]) || (a[0] <= b[0] <= a[1])) return true;
        return false;
    }
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int n = firstList.size();
        int m = secondList.size();
        vector<vector<int>> res;
        int i = 0, j = 0;
        
        while (i < n && j < m)
        {
            int low = max(firstList[i][0], secondList[j][0]);
            int high = min(firstList[i][1], secondList[j][1]);
            
            if (low <= high) 
            {
                res.push_back({low, high});
                if (high == firstList[i][1]) i++;
                else j++;
            }
            else
            {
                if (low == firstList[i][0]) j++;
                else i++;
            }
            
        }
        return res;
    }
};