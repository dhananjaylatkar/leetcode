class Solution {
public:
    
    vector<int> helper (vector<int> &res, vector<vector<int>>& graph, string &labels, int curr, int prev)
    {
        vector<int> count(26);
        count[labels[curr]-'a'] = 1;
        
        for (int node: graph[curr])
        {
            if (node == prev) continue;
            vector<int> _count = helper(res, graph, labels, node, curr);
            for (int i = 0; i < 26; i++)
                count[i] += _count[i];
        }
        res[curr] = count[labels[curr]-'a'];
        return count;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<int> res(n);
        
        vector<vector<int>> graph(n);
        
        for (auto e: edges)
        {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        helper(res, graph, labels, 0, -1);
        return res;
    }
};