class Solution {
public:
//     int min_path = INT_MAX;
    
    // vector<vector<int>> dirs = {{0,1}, {1,0}, {-1,0}, {0,-1}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};
//     void helper(vector<vector<int>>& grid, int x, int y, int path)
//     {
//         int n = grid.size();
//         if (x < 0 || x >= n || y < 0 || y >= n || grid[x][y] == 1)
//         {
//             return;
//         }
//         if (x == n-1 && y == n-1)
//         {
//             min_path = min(min_path, path+1);
//             return;
//         }
        
//         for (int i = 0; i < 8; i++)
//         {
//             int new_x = x + dirs[i][0];
//             int new_y = y + dirs[i][1];
            
//             if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < n)
//             {
//                 cout << new_x << " " << new_y << endl;
//                 if (grid[new_x][new_y] == 0)
//                 {
//                     grid[x][y] = 1;
//                     helper(grid, new_x, new_y, path+1);
//                     grid[x][y] = 0;
//                 }
//             }
//         }
//     }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        int res = 0;
        vector<vector<int>> dirs = {{0,1}, {1,0}, {-1,0}, {0,-1}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};
        queue<pair<int,int>> q;
        q.push({0,0});
        grid[0][0] = 1;
        
        while(!q.empty())
        {
            res++;

            int q_len = q.size();
            
            while (q_len)
            {
                pair<int,int> tmp = q.front(); q.pop();
                // cout << tmp.front << " " << tmp.second << endl;
                if (tmp.first == n-1 && tmp.second == n-1)
                {
                    return res;
                }
                for (int i = 0; i < 8; i++)
                {
                    int x = tmp.first + dirs[i][0];
                    int y = tmp.second + dirs[i][1];
                    
                    if (!(x < 0 || x >= n || y < 0 || y >= n) && grid[x][y] == 0)
                    {
                        q.push({x,y});
                        grid[x][y] = 1;
                    }
                }
                q_len--;
            }
        }
        return -1;
    }
};