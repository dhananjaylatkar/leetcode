class Solution {
public:
    bool is_3x3_valid(vector<vector<char>>& board, int x, int y)
    {
        unordered_set<char> s;
        for (int i = x; i < x+3; i++)
        {
            for (int j = y; j < y+3; j++)
            {
                if (board[i][j] != '.')
                {
                    if (s.find(board[i][j]) != s.end())
                    {
                        return false;
                    }
                    else
                    {
                        s.insert(board[i][j]);
                    }
                }
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        int n = 9;
        
        for (int i = 0; i < n; i++)
        {
            unordered_set<char> s;
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] != '.')
                {
                    if (s.find(board[i][j]) != s.end())
                    {
                        return false;
                    }
                    else
                    {
                        s.insert(board[i][j]);
                    }
                }
            }
        }
        
        for (int j = 0; j < n; j++)
        {
            unordered_set<char> s;
            for (int i = 0; i < n; i++)
            {
                if (board[i][j] != '.')
                {
                    if (s.find(board[i][j]) != s.end())
                    {
                        return false;
                    }
                    else
                    {
                        s.insert(board[i][j]);
                    }
                }
            }
        }
        
        vector<vector<int>> x33 = {
            {0,0}, {0,3}, {0,6},
            {3,0}, {3,3}, {3,6},
            {6,0}, {6,3}, {6,6}
        };

        for (auto it: x33)
        {
            if (!is_3x3_valid(board, it[0], it[1]))
            {
                return false;
            }
        }
        return true;
    }
};