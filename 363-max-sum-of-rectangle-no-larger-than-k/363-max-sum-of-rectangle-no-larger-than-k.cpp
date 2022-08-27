class Solution {
public:
    int find(vector<int> &sum, int k) {
        int res = INT_MIN;
        set<int> s;
        s.insert(0);
        int prefix_sum = 0;
        for (int num: sum)
        {
            prefix_sum += num;
            auto target = s.lower_bound(prefix_sum - k);
            if (target != s.end())
            {
                res = max(res, prefix_sum - *target);
            }
            s.insert(prefix_sum);
        }
        return res;
    }
    
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();
        int res = INT_MIN;
        
        for (int i = 0; i < n; i++)
        {
            vector<int> sum(m);
            for (int j = i; j < n; j++)
            {
                for (int c = 0; c < m; c++)
                {
                    sum[c] += matrix[j][c];
                }
                res = max(res, find(sum, k));
            }
        }
        
        return res;
    }
};