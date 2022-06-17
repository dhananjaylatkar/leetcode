class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> degree(n+1, 0);
        unordered_set<int> s;
        for (int i = 0; i < trust.size(); i++)
        {
            degree[trust[i][1]]++;
            s.insert(trust[i][0]);
        }
        
        for (int i = 1; i < n+1; i++)
        {
            if (degree[i] == n-1 && !s.count(i)) return i;
        }
        return -1;
    }
};