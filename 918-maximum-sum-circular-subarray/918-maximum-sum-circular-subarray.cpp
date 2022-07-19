class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        
        int max_sum = nums[0];
        int sum = nums[0];
        int min_sum = nums[0];
        
        vector<int> min_nums(n, 0);
        min_nums[0] = nums[0];
        
        for (int i = 1; i < n; i++)
        {
            int curr_sum_max = nums[i] + nums[i-1];
            int curr_sum_min = nums[i] + min_nums[i-1];
            int curr = nums[i];
            
            sum += curr;
            nums[i] = max(curr_sum_max, curr);
            min_nums[i] = min(curr_sum_min, curr);
            
            max_sum = max(max_sum, nums[i]);
            min_sum = min(min_sum, min_nums[i]);
        }
        // cout << max_sum << " " << min_sum << " "<< sum << endl;
        if (sum < 0 && sum == min_sum) return max_sum;
        return max(max_sum, sum-min_sum);
    }
};