class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.length();
        vector<int> L_to_R(n, 0);
        vector<int> R_to_L(n, 0);
        char prev = '.';
        int time = 1;
        for (int i = 0; i < n; i++)
        {
            if (dominoes[i] == 'R')
            {
                time = 1;
                prev = dominoes[i];
                continue;
            }
            else if (dominoes[i] == 'L')
            {
                prev = 'L';
            }
            else if (prev == 'R' && dominoes[i] == '.')
            {
                L_to_R[i] = time;
                time++;
            }
        }
        prev = '.';
        time = 1;
        for (int i = n-1; i >= 0; i--)
        {
            if (dominoes[i] == 'L')
            {
                time = 1;
                prev = dominoes[i];
                continue;
            }
            else if (dominoes[i] == 'R')
            {
                prev = 'R';
            }
            else if (prev == 'L' && dominoes[i] == '.')
            {
                R_to_L[i] = time;
                time++;
            }
        }
        string res = "";
        for (int i = 0; i < n; i++)
        {
            if (L_to_R[i] == 0 && R_to_L[i] == 0)
            {
                res += dominoes[i];
            }
            else if (L_to_R[i] == 0)
            {
                res += 'L';
            }
            else if (R_to_L[i] == 0)
            {
                res += 'R';
            }
            else if (L_to_R[i] == R_to_L[i])
            {
                res += '.';
            }
            else if (L_to_R[i] > R_to_L[i])
            {
                res += 'L';
            }
            else
            {
                res += 'R';
            }
        }
        
        return res;
    }
};