class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        unordered_set<int> s;
        for (int num: nums)
        {
            s.insert(num);
        }
        
        for (int i = 0; i < n; i++)
        {
            int curr = nums[i];
            if (!s.count(curr-1))
            {
                int count = 0;

                while (s.count(curr))
                {
                    count++;
                    curr++;
                }
                res = max(res, count);
            }            
        }
        
        return res;
    }
};