class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int res = INT_MAX;
        int min_diff = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            int l = i+1;
            int h = n-1;
            
            while (l < h)
            {
                int tmp = nums[i] + nums[l] + nums[h];
                int diff = abs(target-tmp);
                if (min_diff > diff)
                {
                    min_diff = diff;
                    res = tmp;
                }
                
                if (tmp >= target)
                {
                    h--;
                }
                else
                {
                    l++;
                }
            }
        }
        
        return res;
    }
};