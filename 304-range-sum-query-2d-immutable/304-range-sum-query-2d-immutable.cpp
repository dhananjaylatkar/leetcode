class NumMatrix {
public:
    vector<vector<int>> _matrix;
    NumMatrix(vector<vector<int>>& matrix) {
        _matrix = matrix;
        int m = _matrix.size();
        int n = _matrix[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                _matrix[i][j] += _matrix[i][j-1];
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                _matrix[j][i] += _matrix[j-1][i];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = _matrix[row2][col2];
        if (row1 > 0) sum -= _matrix[row1-1][col2];
        if (col1 > 0) sum -= _matrix[row2][col1-1];
        if (row1 > 0 && col1 > 0)sum += _matrix[row1-1][col1-1];
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */