class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int res = 0;
        
        for (int i = 0; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                matrix[i][j] += matrix[i][j-1];
            }
        }
        
        for (int col1 = 0; col1 < n; col1++)
        {
            for (int col2 = col1; col2 < n; col2++)
            {
                unordered_map<int, int> map;
                map[0] = 1;
                int sum = 0;
                
                for (int row = 0; row < m; row++)
                {
                    sum += matrix[row][col2] - (col1 == 0 ? 0 : matrix[row][col1-1]);
                    if (map.find(sum-target) != map.end())
                    {
                        res += map[sum-target];
                    }
                    map[sum]++;
                }
            }
        }
        
        return res;
    }
};