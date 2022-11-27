class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        vector<unordered_map<int, int>> mp(n);
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                long long diff = (long long)nums[j] - nums[i];
                if (diff > INT_MAX or diff < INT_MIN) continue;
                
                int d = (int)diff;
                
                int n1 = mp[j][d];
                int n2 = mp[i][d];
                
                res += n1;
                
                mp[i][d] = n1+n2+1;
            }
        }
        return res;
    }
};