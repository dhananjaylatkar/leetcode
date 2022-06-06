class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> triag;
        triag.push_back({1});
        if (rowIndex == 0) return {1};
        
        for (int i = 1; i <= rowIndex; i++)
        {
            vector<int> curr = triag.back();
            vector<int> next;
            for (int j = 0; j <= i; j++)
            {
                if (j == 0 || j == i)
                {
                    next.push_back(1);
                }
                else 
                {
                    next.push_back(curr[j]+curr[j-1]);
                }
            }
            if (i==rowIndex) return next;
            triag.push_back(next);
        }
        return {};
    }
};