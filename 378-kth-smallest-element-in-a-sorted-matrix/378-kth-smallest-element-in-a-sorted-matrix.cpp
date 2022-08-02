class Solution {
public:
    int less_nums(vector<vector<int>>& matrix, int num)
    {
        int n = matrix.size();
        
        int res = 0;
        
        for (int i = 0; i < n; i++)
        {
            int l = 0;
            int h = n-1;

            while (l <= h)
            {
                int m = l + (h-l)/2;
                int curr = matrix[i][m];
                
                if (curr > num)
                {
                    h = m-1;
                }
                else
                {
                    l = m+1;
                }
            }
            res += l;
        }
        
        return res;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int l = matrix[0][0];
        int h = matrix[n-1][n-1];
        
        while (l <= h)
        {
            int m = l + (h-l)/2;
            int pos = less_nums(matrix, m);
            if (pos < k)
            {
                l = m+1;
            }
            else
            {
                h = m-1;
            }
        }
        return l;
    }
};