class Solution {
public:
    void helper(vector<vector<int>>& rooms, int idx, vector<bool> &v)
    {
        if (idx == rooms.size()) return;
        v[idx] = true;
        
        for (int i = 0; i < rooms[idx].size(); i++)
        {
            if (!v[rooms[idx][i]])
            helper(rooms, rooms[idx][i], v);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> v(n, false);
        helper(rooms, 0, v);
        
        for (int i = 0; i < n; i++)
        {
            if (!v[i]) return false;
        }
        return true;
    }
};