class Solution {
public:
    string convert (string &num)
    {
        string res = "";
        int n = num.length();
        int i = 0;
        while (i < n)
        {
            int f = 0;
            char curr = num[i];
            
            while (i < n && curr == num[i])
            {
                f++;
                i++;
            }
            res += to_string(f) + curr;
        }
        return res;
    }
    string countAndSay(int n) {
        if (n == 1)
        {
            return "1";
        }
        string p = countAndSay(n-1);
        return convert(p);
    }
};