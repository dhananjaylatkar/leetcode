class Solution {
public:
    int getSum(vector<vector<int>>& mat, int tx, int ty, int bx, int by)
    {
        int m = mat.size();
        int n = mat[0].size();
        
        if (tx < 0) tx = 0;
        if (ty < 0) ty = 0;
        if (bx >= m) bx = m-1;
        if (by >= n) by = n-1;
        
        int sumtop = (tx > 0) ? mat[tx-1][by] : 0;
        int sumright = (ty > 0) ? mat[bx][ty-1] : 0;
        int sumtopright = (tx > 0 && ty > 0) ? mat[tx-1][ty-1] : 0;
        
        return mat[bx][by] - sumtop - sumright + sumtopright;
    }
        
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> res(m, vector<int>(n));
        
        for (int i = 0; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                mat[i][j] += mat[i][j-1];
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                mat[j][i] += mat[j-1][i];
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                res[i][j] = getSum(mat, i-k, j-k, i+k, j+k);
            }
        }
        
        return res;
    }
};