class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;
public:
    UnionFind () {
        parent = vector(26, 0);
        rank = vector(26, 0);
        for (int i = 0; i < 26; i++)
        {
            parent[i] = i;
        }
    }
    
    int find(int val)
    {
        if (parent[val] == val)
        {
            return val;
        }
        
        return find(parent[val]);
    }
    
    void unions(int x, int y)
    {
        int x_rep = find(x);
        int y_rep = find(y);
        
        if (x_rep == y_rep) return;
        
        if (rank[x_rep] < rank[y_rep]) parent[x_rep] = y_rep;
        else if (rank[x_rep] > rank[y_rep]) parent[y_rep] = x_rep;
        else
        {
            parent[y_rep] = x_rep;
            rank[x_rep]++;
        }
    }
};
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        UnionFind uf = UnionFind();
        
        for (string eq: equations)
        {
            if (eq[1] == '=')
            {
                uf.unions(eq[0]-'a', eq[3]-'a');
            }
        }
        
        for (string eq: equations)
        {
            if (eq[1] == '!')
            {
                if (uf.find(eq[0]-'a') == uf.find(eq[3]-'a'))
                {
                    return false;
                }
            }
        }
        return true;
    }
};