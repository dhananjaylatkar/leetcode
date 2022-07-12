class Solution {
public:
    vector<int> sides;
    int possible_side;
    bool helper(vector<int>& matchsticks, int idx)
    {
        int n = matchsticks.size();
        
        
        if (idx == n && sides[0] != 0 && sides[0] == sides[1] && sides[0] == sides[2] && sides[0] == sides[3])
        {
            return true;
        }
        
        if (idx == n) return false;
        
        bool p = false;
        for (int i = 0; i < 4; i++)
        {
            
            if (sides[i]+matchsticks[idx] <= possible_side)
            {
                sides[i] += matchsticks[idx];
                p = helper(matchsticks, idx+1);
                if (p) return true;
                sides[i] -= matchsticks[idx];
            }
        }
        return p;
    }
    
    static bool mycmp(int a, int b)
    {
        return a > b;
    }
    bool makesquare(vector<int>& matchsticks) {
        int n = matchsticks.size();
        if (n < 4) return false;
        sort(matchsticks.begin(), matchsticks.end(), mycmp);
        sides = {0,0,0,0};
        int sum = 0;
        for (int i = 0; i < n; i++) sum += matchsticks[i];
        
        possible_side = sum/4;
        
        if (possible_side*4 != sum) return false;
        
        return helper(matchsticks, 0);
    }
};