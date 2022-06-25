class Solution {
public:
    unordered_set<int> s;
    bool helper(int n)
    {
        if (n == 1) return true;
        if (s.count(n)) return false;
        else
        {
            s.insert(n);
        }
        
        int tmp = 0;
        while (n)
        {
            tmp += (n % 10) * (n % 10);
            n /= 10;
        }
        
        return helper(tmp);
    }
    bool isHappy(int n) {
        return helper(n);
    }
};