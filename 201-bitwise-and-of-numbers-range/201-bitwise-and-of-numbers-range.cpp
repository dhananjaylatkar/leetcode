class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        // if (left == right) return left;
        // long long int res = left;
        // for (long long int i = left+1; i <= right; i++)
        // {
        //     // cout << i << endl;
        //     res = res & i;
        //     if (!res) return res;
        // }
        // return res;
        
        /*
        l = 10100
        r = 10111
        
        shift both l and r to right until they are equal
        once the are equal we know how many 0 bits are at the end
        and we can right shift by number of 0 bits to get the ans.
        */
        int count = 0;
        
        while (left != right)
        {
            count ++;
            left = left >> 1;
            right = right >> 1;
        }
        
        return left << count;
    }
};