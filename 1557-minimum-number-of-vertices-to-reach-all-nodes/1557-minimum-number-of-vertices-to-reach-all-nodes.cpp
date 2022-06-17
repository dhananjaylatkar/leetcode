class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> incoming(n, 0);
        
        for(int i = 0; i < edges.size(); i++)
        {
            incoming[edges[i][1]]++;
        }
        
        vector<int> res;
        for(int i = 0; i < n; i++)
        {
            if (!incoming[i]) res.push_back(i);
        }
        return res;
    }
};