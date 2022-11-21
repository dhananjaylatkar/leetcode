class Solution {
public:
    bool on_border(int x, int y, int m, int n)
    {
        return (x == 0) || (y == 0) || (x == m-1) || (y == n-1);
    }
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();
        queue<vector<int>> q;
        vector<vector<bool>> visited(m, vector(n, false));
        q.push({entrance[0], entrance[1], 0});
        vector<vector<int>> dirs = {{0,1}, {1,0}, {-1,0}, {0,-1}};
        while (q.size())
        {
            int len = q.size();
            
            for (int i = 0; i < len; i++)
            {
                vector<int> curr = q.front();
                q.pop();
                
                if (!(curr[0] == entrance[0] && curr[1] == entrance[1]) && on_border(curr[0], curr[1], m, n))
                {
                    return curr[2];
                }
                
                for (auto dir: dirs)
                {
                    int x = curr[0] + dir[0];
                    int y = curr[1] + dir[1];
                    if (x < 0 || y < 0 || x >= m || y >= n)
                    {
                        continue;
                    }
                    if (visited[x][y]) continue;
                    if (maze[x][y] == '.')
                    {
                        q.push({x, y, curr[2]+1});
                        visited[x][y] = true;
                    }
                }
            }
        }
        return -1;
    }
};