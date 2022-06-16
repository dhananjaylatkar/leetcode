class Solution {
public:
    vector<vector<int>> dirs = {{0,1}, {1,0}, {-1,0}, {0,-1}};
    void markEm(vector<vector<char>>& board, int x, int y)
    {
        int m = board.size();
        int n = board[0].size();
        
        if (x < 0 || x >= m || y < 0 || y >= n || board[x][y] != 'O')
        {
            return;
        }
        board[x][y] = 'D';
        
        for (int i = 0; i < 4; i++)
        {
            int _x = x + dirs[i][0];
            int _y = y + dirs[i][1];
            // cout << _x << " " << _y<< endl; 
            if (!(_x < 0 || _x >= m || _y < 0 || _y >= n))
            {
                if (board[_x][_y] == 'O')
                {
                    markEm(board, _x, _y);
                }
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        // cout << m << " " << n << endl;
        for (int i = 0; i < m; i++)
        {
            // cout << i << " 0"<< endl;   
            markEm(board, i, 0);
            // cout << i << " " << n-1<< endl; 
            markEm(board, i, n-1);
            
        }
         // cout << "=======" << endl;
        for (int j = 0; j < n; j++)
        {
            // cout << j << endl;
            markEm(board, 0, j);
            markEm(board, m-1, j);
        }
        
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // cout << board[i][j] << " ";
                if (board[i][j] == 'D')
                {
                    board[i][j] = 'O';
                }
                else if (board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
            }
            // cout << endl;
        }
    }
};