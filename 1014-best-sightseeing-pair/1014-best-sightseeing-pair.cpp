class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int max_till_now = values[0];
        int res = 0;
        for (int i = 1; i < values.size(); i++)
        {
            res = max(res, max_till_now+values[i]-i);
            
            max_till_now = max(max_till_now, values[i]+i);
        }
        
        return res;
    }
};