class Solution {
public:
    bool helper(vector<vector<int>> &graph, int curr, vector<int> &path, unordered_set<int> &v, unordered_set<int> &cycle)
    {   
        if (v.count(curr))
        {
            return true;
        }
        if (cycle.count(curr))
        {
            return false;
        }
        
        
        cycle.insert(curr);
        for (int i = 0; i < graph[curr].size(); i++)
        {   
            if (helper(graph, graph[curr][i], path, v, cycle) == false)
            {
                return false;
            }
        }
        cycle.erase(curr);
        v.insert(curr);
        path.push_back(curr);
        return true;
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        
        int n = prerequisites.size();
        for (int i = 0; i < n; i++)
        {
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        unordered_set<int> v;
        unordered_set<int> cycle;
        vector<int> path;
        for (int i = 0; i < numCourses; i++)
        {
            
            if (!helper(graph, i, path, v, cycle))
            {
                return {};
            }

        }
        return path;
    }
};