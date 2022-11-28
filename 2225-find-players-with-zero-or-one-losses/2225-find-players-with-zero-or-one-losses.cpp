class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        
        map<int, int> loses;
        
        for (auto match: matches)
        {
            loses[match[0]];
            loses[match[1]]++;
        }
        
        vector<int> no_loss;
        vector<int> one_loss;
        
        for (auto l: loses)
        {
            if (l.second == 0)
            {
                no_loss.push_back(l.first);
            }
            else if (l.second == 1)
            {
                one_loss.push_back(l.first);
            }
        }
        
        return {no_loss, one_loss};
    }
};