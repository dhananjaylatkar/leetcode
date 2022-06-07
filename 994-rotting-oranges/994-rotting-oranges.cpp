class Solution {
public:
    vector<vector<int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({i,j});
                }
                
            }
        }
        int res = 0;
        while(!q.empty())
        {
            int q_len = q.size();
            
            bool new_orange = false;
            for (int j = 0; j < q_len; j++)
            {
                pair<int, int> curr = q.front(); q.pop();
                for (int i = 0; i < 4; i++)
                {
                    int new_x = curr.first + dirs[i][0];
                    int new_y = curr.second + dirs[i][1];

                    if (new_x < 0 || new_x >= m || new_y < 0 || new_y >= n) continue;

                    if (grid[new_x][new_y] == 1)
                    {
                        new_orange = true;
                        grid[new_x][new_y] = 2;
                        q.push({new_x, new_y});
                    }
                }
            }
            if (new_orange) res ++;
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    return -1;
                }
            }
        }
        return res;
    }
};