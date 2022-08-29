class Solution {
public:
    long long int reverse (int x) {
        long long int res = 0;
        
        while (x)
        {
            res = 10*res + x%10;
            x /= 10;
        }
        return res;
    }
    bool isPalindrome(int x) {
        if (x < 0) return false;
        
        return (long long int)x == reverse(x);
    }
};