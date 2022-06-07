class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> res(m, vector(n, INT_MAX));
        
        queue<pair<int,int>> q;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == 0)
                {
                    res[i][j] = 0;
                    q.push({i,j});
                }
                
            }
        }
        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        
        while(!q.empty())
        {
            pair<int, int> curr = q.front(); q.pop();
            
            for (int i = 0; i < 4; i++)
            {
                int new_i = curr.first + dirs[i][0];
                int new_j = curr.second + dirs[i][1];
                if (new_i < 0 || new_j < 0 || new_i >= m || new_j >= n) continue;
                if (res[new_i][new_j] > res[curr.first][curr.second] + 1)
                {
                    res[new_i][new_j] = res[curr.first][curr.second] + 1;
                    q.push({new_i, new_j});
                }
            }
        }
        return res;
    }
};