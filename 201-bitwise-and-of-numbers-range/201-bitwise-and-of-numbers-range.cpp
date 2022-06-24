class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if (left == right) return left;
        long long int res = left;
        for (long long int i = left+1; i <= right; i++)
        {
            // cout << i << endl;
            res = res & i;
            if (!res) return res;
        }
        return res;
    }
};