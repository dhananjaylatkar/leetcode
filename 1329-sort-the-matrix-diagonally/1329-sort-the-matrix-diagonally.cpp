class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        for (int i = 0; i < n; i++)
        {
            // i,0
            vector<int> diag;
            int _i = i;
            int _j = 0;
            
            while (_i < n && _j < m)
            {
                diag.push_back(mat[_i][_j]);
                _i++;
                _j++;
            }
            
            sort(diag.begin(), diag.end());
            
            int k = 0;
            _i = i;
            _j = 0;
            while (k < diag.size())
            {
                mat[_i][_j] = diag[k];
                k++;
                _i++;
                _j++;
            }
        }
        
        for (int j = 1; j < m; j++)
        {
            // 0,j
            vector<int> diag;
            int _i = 0;
            int _j = j;
            
            while (_i < n && _j < m)
            {
                diag.push_back(mat[_i][_j]);
                _i++;
                _j++;
            }
            
            sort(diag.begin(), diag.end());
            
            int k = 0;
            _i = 0;
            _j = j;
            while (k < diag.size())
            {
                mat[_i][_j] = diag[k];
                k++;
                _i++;
                _j++;
            }
        }
        
        return mat;
    }
};