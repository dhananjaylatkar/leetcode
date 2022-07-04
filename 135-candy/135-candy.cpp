class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        
        vector<int> c(n, 1);
        
        for (int i = 1; i < n; i++)
        {   
            if (ratings[i-1] < ratings[i])
            {
                c[i] = c[i-1] + 1;
            }
        }
        int res = c[n-1];
        for (int i = n-2; i >= 0; i--)
        {
            if (ratings[i+1] < ratings[i])
            {
                c[i] = max(c[i+1] + 1, c[i]);
            }
            res += c[i];
        }
        return res;
    }
};