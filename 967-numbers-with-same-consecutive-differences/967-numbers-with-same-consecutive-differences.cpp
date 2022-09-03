class Solution {
public:
    vector<int> res;
    void helper(int num, int n, int k)
    {
        if (floor(log10(num))+1 == n)
        {
            res.push_back(num);
            return;
        }
        
        int last_dig = num % 10;
        if (last_dig+k < 10)
        {
            helper(num*10 + (last_dig+k), n, k);
        }
        
        if (last_dig+k != last_dig-k && last_dig-k >= 0)
        {
            helper(num*10 + (last_dig-k), n, k);
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        for (int i = 1; i <= 9; i++)
        {
            helper(i, n, k);
        }
        return res;
    }
};