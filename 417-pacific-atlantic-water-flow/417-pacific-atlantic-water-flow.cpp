class Solution {
public:
    void reachFromOcean(vector<vector<int>>& heights, vector<vector<int>>& v, queue<pair<int,int>> q)
    {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> dirs = {{1,0}, {0,1}, {-1,0}, {0,-1}};
        
        while (!q.empty())
        {   
            pair<int,int> curr = q.front();
            q.pop();
            
            for (int i = 0; i < 4; i++)
            {
                int new_x = curr.first + dirs[i][0];
                int new_y = curr.second + dirs[i][1];

                if (new_x >= 0 && new_y >= 0 && new_x < m && new_y < n)
                {
                    if (v[new_x][new_y] == 0 && heights[new_x][new_y] >= heights[curr.first][curr.second])
                    {
                        v[new_x][new_y] = 1;
                        q.push({new_x, new_y});
                    }
                    
                }
            }
        }
        return;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> res;
        vector<vector<int>> vp(m, vector<int>(n, 0));
        queue<pair<int,int>> qp;
        
        vector<vector<int>> va(m, vector<int>(n, 0));
        queue<pair<int,int>> qa;
        for (int i = 0; i < n; i++)
        {
            vp[0][i] = 1;
            qp.push({0,i});
            
            va[m-1][i] = 1;
            qa.push({m-1, i});
        }
        
        for (int j = 0; j < m; j++)
        {
            vp[j][0] = 1;
            qp.push({j,0});
            
            va[j][n-1] = 1;
            qa.push({j,n-1});
        }
        reachFromOcean(heights, va, qa);
        reachFromOcean(heights, vp, qp);
        
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (va[i][j] && vp[i][j])
                {
                    res.push_back({i,j});
                }
            }
        }
        return res;
    }
};