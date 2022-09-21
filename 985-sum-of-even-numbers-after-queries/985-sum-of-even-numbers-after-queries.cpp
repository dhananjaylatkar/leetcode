class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> res;
        int even_sum = 0;
        
        for (int num: nums)
        {
            if (num%2 == 0) even_sum += num;
        }
        
        for (vector<int> q: queries)
        {
            int curr_num = nums[q[1]];
            int updated_num = curr_num + q[0];
            if (curr_num%2 == 0) // even
            {
                if (updated_num%2 == 0) // even
                {
                    even_sum += q[0];
                }
                else // odd
                {
                    even_sum -= curr_num;
                }
            }
            else // odd
            {
                if (updated_num%2 == 0) // even
                {
                    even_sum += updated_num;
                }
            }
            
            nums[q[1]] = updated_num;
            res.push_back(even_sum);
        }
        
        return res;
    }
};