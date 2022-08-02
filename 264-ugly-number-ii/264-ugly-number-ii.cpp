class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n);
        dp[0] = 1; // 1 is ugly
        
        int p2 = 0;
        int p3 = 0;
        int p5 = 0;
        
        for (int i = 1; i < n; i++)
        {
            int two = 2*dp[p2];
            int three = 3*dp[p3];
            int five = 5*dp[p5];
            dp[i] = min(two, min(three, five));
            
            if (dp[i] == two)   p2++;
            if (dp[i] == three) p3++;
            if (dp[i] == five)  p5++;
        }
        
        return dp[n-1];
    }
};