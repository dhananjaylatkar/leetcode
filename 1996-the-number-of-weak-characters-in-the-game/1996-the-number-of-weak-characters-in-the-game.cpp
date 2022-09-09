class Solution {
public:
    static bool comp (vector<int> &a,vector<int> &b)
    {
        if(a[0]!=b[0])
            return a[0]>b[0];
        return a[1]<b[1];
    }
    int numberOfWeakCharacters(vector<vector<int>>& prop) {
        sort(prop.begin(), prop.end(), comp);
        int max_till_now = INT_MIN;
        int res = 0;
        for(auto p: prop)
        {
            if(max_till_now > p[1]) 
                res++;
            else
                max_till_now = p[1];
        }
        return res;
    }
};