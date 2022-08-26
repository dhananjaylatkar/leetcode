class Solution {
public:
    vector<int> count_digits(int n) {
        vector<int> res(10, 0);
        
        while (n)
        {
            res[n%10]++;
            n = n/10;
        }
        
        return res;
    }
    bool reorderedPowerOf2(int n) {
        vector<int> c = count_digits(n);
        
        for (int i = 0; i < 31; i++)
        {
            if (c == count_digits(1 << i))
            {
                return true;
            }
        }
        
        return false;
    }
};