class Solution {
public:
    int helper(vector<vector<int>>& graph, vector<bool>& hasApple, int curr, int par) {
        int time = 0;
        
        for (int child: graph[curr]) 
        {
            if (child == par) continue;
            
            int child_time = helper(graph, hasApple, child, curr);

            if (child_time or hasApple[child]) 
            {
                time += 2 + child_time;
            }
        }

        return time;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> graph(n);
        
        for (vector<int> e: edges)
        {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        
        return helper(graph, hasApple, 0, -1);
    }
};