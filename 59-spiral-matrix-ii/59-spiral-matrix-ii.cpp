class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector(n,0));
        int top = 0, right = n-1, bottom = n-1, left = 0;
        int num = 1;
        while(top <= bottom && left <= right)
        {
            for (int i = left; i <= right; i++)
            {
                res[top][i] = num;
                num++;
            }
            top++;
            for (int i = top; i <= bottom; i++)
            {
                res[i][right] = num;
                num++;
            }
            right--;
            
            if (top <= bottom)
            {
                for (int i = right; i >= left; i--)
                {
                    res[bottom][i] = num;
                    num++;
                }
                bottom--;
            }
            if (left <= right)
            {
                for (int i = bottom; i >= top; i--)
                {
                    res[i][left] = num;
                    num++;
                }
                left++;
            }
        }
        
        return res;
        
    }
};