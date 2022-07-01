class Solution {
public:
    static bool mycmp(vector<int> &a, vector<int> &b)
    {
        return a[1] > b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), mycmp);
        int n = boxTypes.size();
        int res = 0;
        
        for (int i = 0; i < n; i++)
        {
            if (truckSize <= 0) break;
            
            if (truckSize - boxTypes[i][0] >= 0)
            {
                res += boxTypes[i][0]*boxTypes[i][1];
                truckSize -= boxTypes[i][0];
            }
            else
            {
                res += truckSize*boxTypes[i][1];
                break;
            }
        }
        
        return res;
    }
};