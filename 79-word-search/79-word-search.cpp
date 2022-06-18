class Solution {
public:
    vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    bool helper(vector<vector<char>>& board, string &word, int idx, int x, int y, vector<vector<int>>& v)
    {
        if (idx == word.length()-1)
        {
            // cout << "tada";
            return true;
        }
        int m = board.size();
        int n = board[0].size();
        if (x < 0 || x >= m || y < 0 || y >= n)
        {
            return false;
        }
        if (board[x][y] != word[idx])
        {
            return false;
        }
        // cout << x << " " << y << " " << " " << board[x][y] << endl;
        
        for (int i = 0; i < 4; i++)
        {
            int _x = x + dirs[i][0];
            int _y = y + dirs[i][1];
            if (_x < 0 || _x >= m || _y < 0 || _y >= n) continue;
            
            if (board[_x][_y] == word[idx+1] && v[_x][_y] != 1)
            {
                v[x][y] = 1;
                bool res = helper(board, word, idx+1, _x, _y, v);
                v[x][y] = 0;
                if (res) return true;
            }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        bool ans = false;
        
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == word[0])
                {
                    vector<vector<int>> v(m, vector<int>(n,0));
                    ans = helper(board, word, 0, i, j, v);
                    if (ans) return true;
                }
            }
        }
        return false;
    }
};