class Solution {
public:
    // int helper(int n)
    // {
    //     if (n == 0)
    //     {
    //        return 0;
    //     }
    //     if (n == 1)
    //     {
    //         return 1;
    //     }
    //     return helper(n-1)+helper(n-2);
    // }
    
    int fib(int n) {
        if (n == 0 || n == 1) return n;
        vector<int> table(n+1);
        table[0] = 0;
        table[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            table[i] = table[i-1] + table[i-2];
        }
        return table[n];
    }
};