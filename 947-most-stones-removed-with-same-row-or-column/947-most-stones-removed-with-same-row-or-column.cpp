class UnionFind {
public:
    unordered_map<int, int> parents;
    unordered_map<int, int> rank;
    int count;
    UnionFind (vector<vector<int>>& stones)
    {
        for (auto s: stones)
        {
            int row = -(s[0] + 1);
            int col = s[1] + 1;
            parents[row] = row;
            parents[col] = col;
            rank[row] = 1;
            rank[col] = 1;
        }
        count = parents.size();
    }
    
    int find_parent(int node)
    {
        int res = node;
        
        while (res != parents[res])
        {
            res = parents[res];
        }
        return res;
    }
    
    void _union(int n1, int n2)
    {
        int p1 = find_parent(n1);
        int p2 = find_parent(n2);
        if (p1 == p2) return;
        
        if (rank[p2] > rank[p1])
        {
            parents[p1] = p2;
            rank[p2] += rank[p1];
        }
        else
        {
            parents[p2] = p1;
            rank[p1] += rank[p2];
        }
        count--;
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        
        // Union-Find
        UnionFind u(stones);

        for (auto s: stones)
        {
            int row = -(s[0] + 1);
            int col = s[1] + 1;
            u._union(row, col);
        }
        
        return stones.size()-u.count;
    }
};