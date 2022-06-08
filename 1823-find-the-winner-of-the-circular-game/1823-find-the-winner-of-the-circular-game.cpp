class Solution {
public:
    int josephus(int n, int k)
    {
        if (n == 1) return 0;
        
        return (josephus(n-1, k) + k) % n;
    }
    int findTheWinner(int n, int k) {
        // josephus works for n starting with 0
        // for n starting with 1, add 1 to the output.
        return 1 + josephus(n, k);
    }
};