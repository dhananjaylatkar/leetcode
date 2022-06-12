class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int res = 0;
        int sum = 0;
        int n = nums.size();
        unordered_set<int> s;
        int i = 0, j = 0;
        while (i < n && j < n)
        {
            if (s.find(nums[i]) == s.end())
            {
                s.insert(nums[i]);
                sum += nums[i];
            }
            else
            {
                res = max(res, sum);
                
                while(j < n && nums[j] != nums[i])
                {
                    s.erase(nums[j]);
                    sum -= nums[j];
                    j++;
                }
                j++;
            }
            i++;
        }
        res = max(res, sum);
        return res;
    }
};