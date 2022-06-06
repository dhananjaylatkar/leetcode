class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0;

        int prefix_sum = 0;
        unordered_map<int,int> s;
        for (int i = 0; i < nums.size(); i++)
        {
            prefix_sum += nums[i];

            if (prefix_sum == k) 
            {
                res++;
            }
            if (s.find(prefix_sum-k) != s.end())
            {
                res+=s[prefix_sum-k];
            }
            s[prefix_sum]++;
        }
        
        return res;
    }
};