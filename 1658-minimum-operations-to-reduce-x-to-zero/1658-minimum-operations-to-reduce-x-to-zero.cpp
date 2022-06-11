class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = 0;
        for (int num: nums) sum += num;
        sum = sum - x;
        int n = nums.size();
        if (sum == 0) return n;
        if (sum < 0) return -1;
        // cout << "sum "<< sum << endl;
        
        unordered_map<int, int> m; // prefix_sum: index
        int prefix_sum = 0;
        int max_sub = 0;
        
        for (int i = 0; i < n; i++)
        {
            prefix_sum += nums[i];
            if (nums[i] == sum)
            {
                max_sub = max(max_sub, 1);
            }
            if (prefix_sum == sum)
            {
                max_sub = max(max_sub, i + 1);
            }
            
            if (m.find(prefix_sum-sum) != m.end())
            {
                max_sub = max(max_sub, i - m[prefix_sum-sum]);
            }

            m[prefix_sum] = i;
        }
        
        return max_sub == 0 ? -1 : n - max_sub;
    }
};