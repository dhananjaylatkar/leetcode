class Solution {
public:
    /*
    1001
    0110
    */

    int helper (vector<vector<int>> &arr, int idx, int prev)
    {
        int n = arr.size();
        if (idx == n)
        {
            return 0;
        }
        
        int p1 = helper(arr, idx+1, prev);
        int p2 = 0;
        
        if ((arr[idx][0] ^ prev) == (arr[idx][0] | prev))
        {
            p2 = arr[idx][1] + helper (arr, idx+1, (arr[idx][0] | prev));
        }
        
        return max(p1, p2);
    }
    int maxLength(vector<string>& arr) {
        vector<vector<int>> inp;
        
        for (string s: arr)
        {
            int len = s.length();
            int mask = 0;
            int prev = -1;
            int count = 0;
            for (char c: s)
            {
                prev = mask;
                mask = mask | (1 << int(c-'a'));
                if (prev != mask) count++;
            }
            
            if (count == len) inp.push_back({mask, len});
            
        }
        return helper (inp, 0, 0);
    }
};