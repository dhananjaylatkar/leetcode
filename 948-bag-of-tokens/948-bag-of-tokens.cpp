class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        
        int l = 0;
        int h = tokens.size()-1;
        int res = INT_MIN;
        int score = 0;
        while (l <= h && (power >= tokens[l] || score > 0))
        {
            while (l <= h && power >= tokens[l])
            {
                score++;
                power -= tokens[l];
                l++;
                // cout << "up " << score << " " << power << endl;
            }
            res = max(res, score);
            
            if (l <= h && score > 0)
            {
                score--;
                power += tokens[h];
                h--;
                // cout << "down " << score << " " << power << endl;
            }
        }
        
        return res==INT_MIN ? 0: res;
    }
};