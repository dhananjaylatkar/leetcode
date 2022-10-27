class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int res = 0;
        vector<pair<int, int>> ones_1;
        vector<pair<int, int>> ones_2;
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (img1[i][j] == 1) ones_1.push_back({i,j});
                if (img2[i][j] == 1) ones_2.push_back({i,j});
            }
        }

        map<pair<int, int>, int> m;
        
        for (int i = 0; i < ones_1.size(); i++)
        {
            for (int j = 0; j < ones_2.size(); j++)
            {
                int x = ones_1[i].first - ones_2[j].first;
                int y = ones_1[i].second - ones_2[j].second;
                
                m[{x, y}]++;
                res = max(res, m[{x, y}]);
            }
        }
        
        return res;
    }
};