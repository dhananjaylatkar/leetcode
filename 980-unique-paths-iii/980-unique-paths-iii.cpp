class Solution {
public:
    void helper(int x, int y, vector<vector<int>>& grid, int m, int n, int zero_count, int zero_count_now, int &res)
    {
        vector<vector<int>> dirs = {{1,0}, {0,1}, {-1,0}, {0,-1}};
        
        for (auto dir: dirs)
        {
            int new_x = x + dir[0];
            int new_y = y + dir[1];
            
            if (new_x >= 0 and new_x < m and new_y >= 0 and new_y < n)
            {
                if (grid[new_x][new_y] == 2)
                {
                    // cout << zero_count << " " << zero_count_now << endl;
                    if (zero_count == zero_count_now)
                        res++;
                }
                else if (grid[new_x][new_y] == 0)
                {
                    grid[new_x][new_y] = -1;
                    helper(new_x, new_y, grid, m, n, zero_count, zero_count_now+1, res);
                    grid[new_x][new_y] = 0;
                }
                
            }
        }
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int zero_count = 0;
        int start_x = 0;
        int start_y = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 0)
                {
                    zero_count++;
                }
                else if (grid[i][j] == 1)
                {
                    start_x = i;
                    start_y = j;
                }
            }
        }
        int res = 0;
        helper(start_x, start_y, grid, m, n, zero_count, 0, res);
        return res;
    }
};