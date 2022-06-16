class Solution {
public:
    vector<vector<int>> res;
    void helper(vector<vector<int>>& graph, int curr_node, vector<int> &path)
    {
        if (curr_node >= graph.size()) return;
        if (curr_node == graph.size()-1)
        {
            res.push_back(path);
            return;
        }
        
        for (int i = 0; i < graph[curr_node].size(); i++)
        {
            path.push_back(graph[curr_node][i]);
            helper(graph, graph[curr_node][i], path);
            path.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> path = {0};
        helper(graph, 0, path);
        return res;
    }
};