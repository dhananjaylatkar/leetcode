class Solution {
public:
    static bool mycmp(vector<int> &a, vector<int> &b)
    {
        if (a[1] == b[1]) return a[0] > b[0];
        return a[1] < b[1];
    }
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<vector<int>> inp;
        int n = capacity.size();
        for (int i = 0; i < n; i++)
        {
            inp.push_back({rocks[i], capacity[i]-rocks[i]});
        }
        
        sort(inp.begin(), inp.end(), mycmp);
        
        int res = 0;
        
        for (auto it: inp)
        {
            if (additionalRocks >= it[1])
            {
                res++;
                additionalRocks -= it[1];
            }
        }
        
        return res;
    }
};