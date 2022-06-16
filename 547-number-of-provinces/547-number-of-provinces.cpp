class Solution {
public:
    void helper(vector<vector<int>> &graph, int curr_node, vector<bool> &v)
    {
        int n = v.size();
        
        if (curr_node >= n) return;
        v[curr_node] = true;
        for (int i = 0; i < graph[curr_node].size(); i++)
        {
            if (v[graph[curr_node][i]] == false)
            {
                helper(graph, graph[curr_node][i], v);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> graph;
        
        for (int i = 0; i < n; i++)
        {
            vector<int> tmp;
            for (int j = 0; j < n; j++)
            {
                if (isConnected[i][j] == 1 && i != j)
                {
                    tmp.push_back(j);
                }
            }
            graph.push_back(tmp);
        }
        // for (int i = 0; i < n; i++)
        // {
        //     for (int val: graph[i]) cout << val << " "; cout << endl;
        // }
        vector<bool> v(n, false);
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            if (v[i] == false)
            {
                res++;
                helper(graph, i, v);
            }
        }
        return res;
    }
};