class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int min_prod = 1;
        int max_prod = 1;
        
        int res = INT_MIN;
        for (int num: nums) res = max(num, res);
        
        for (int num: nums)
        {
            if (num == 0)
            {
                min_prod = 1;
                max_prod = 1;
                continue;
            }
            int tmp = num * max_prod;
            max_prod = max(num, max(tmp, num * min_prod));
            min_prod = min(num, min(tmp, num * min_prod));
            
            // cout << max_prod << " " << min_prod << endl;
            res = max(res, max_prod);
        }

        return res;
    }
};