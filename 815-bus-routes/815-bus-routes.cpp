class Solution {
public:
    bool isIntersection(vector<int> &a, vector<int> &b)
    {   
        int i = 0;
        int j = 0;
        
        while (i < a.size() && j < b.size())
        {
            if (a[i] == b[j]) 
            {
                return true;
            }
            
            else if (a[i] < b[j])
            {
                i++;
            }
            else
            {
                j++;
            }
        }
        return false;
    }
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (target == source)
        {
            return 0;
        }
        
        int n = routes.size();
        for (int i = 0; i < n; i++)
        {
            sort(routes[i].begin(), routes[i].end());
        }

        vector<vector<int>> graph(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = i+1; j < n; j++)
            {
                if (i != j && isIntersection(routes[i], routes[j]))
                {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }

        unordered_set<int> visited;
        unordered_set<int> targets;
        queue<pair<int,int>> q; // node, depth
        
        for (int i = 0; i < n; i++)
        {
            int idx = lower_bound(routes[i].begin(), routes[i].end(), source) - routes[i].begin();
            if (idx < routes[i].size() && routes[i][idx] == source)
            {
                visited.insert(i);
                q.push({i,0});
            }
            
            idx = lower_bound(routes[i].begin(), routes[i].end(), target) - routes[i].begin();
            if (idx < routes[i].size() && routes[i][idx] == target)
            {
                targets.insert(i);
            }
        }

        while (!q.empty())
        {
            pair<int, int> curr = q.front();
            q.pop();
            
            if (targets.count(curr.first))
            {
                return curr.second+1;
            }
            
            for (int i = 0; i < graph[curr.first].size(); i++)
            {
                if (visited.count(graph[curr.first][i]) == 0)
                {
                    visited.insert(graph[curr.first][i]);
                    q.push({graph[curr.first][i], curr.second+1});
                }
            }
        }

        return -1;
    }
};