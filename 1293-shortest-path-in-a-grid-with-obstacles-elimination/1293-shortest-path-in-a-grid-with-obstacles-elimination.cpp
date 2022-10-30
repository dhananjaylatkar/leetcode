class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int res = 0;
        
        queue<vector<int>> q;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dir = {{0,1}, {1,0}, {-1,0}, {0, -1}};
        vector<vector<vector<bool>>> visited = vector(m, vector(n, vector(k+1, false)));
        
        q.push({0, 0, k});
        
        while (!q.empty())
        {
            int len = q.size();
            
            while (len--)
            {
                vector<int> curr = q.front();
                q.pop();

                if (curr[0] == m-1 && curr[1] == n-1) return res;
                
                for (int j = 0; j < 4; j++)
                {
                    int _x = curr[0] + dir[j][0];
                    int _y = curr[1] + dir[j][1];
                    int obstacle = curr[2];
                    
                    if (_x >= 0 && _x < m && _y >= 0 && _y < n)
                    {
                        if (grid[_x][_y] == 0 && !visited[_x][_y][obstacle])
                        {
                            visited[_x][_y][obstacle] = true;
                            q.push({_x, _y, obstacle});
                        }
                        if (grid[_x][_y] == 1 && obstacle > 0 && !visited[_x][_y][obstacle-1])
                        {
                            visited[_x][_y][obstacle-1] = true;
                            q.push({_x, _y, obstacle-1});
                        }
                    }
                }
            }
            res++;
        }
        
        return -1;
    }
};