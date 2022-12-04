class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        vector<long long int> cumm(n);
        cumm[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            cumm[i] += cumm[i-1]+nums[i];
        }
        
        int res = 0;
        long long int min_diff = INT_MAX;
        
        for (int i = 0; i < n; i++)
        {
            long long int left = cumm[i]/(i+1);
            long long int right = i == n-1 ? 0 : (cumm[n-1] - cumm[i])/(n-i-1);
            long long int diff = abs(left-right);
            // cout << i << " " << left << " " << right << " " << diff << endl;
            if (diff < min_diff)
            {
                min_diff = diff;
                res = i;
            }
        }
        return res;
    }
};