class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s;
        int n = nums.size();
        vector<int> nums_next_gre(n);
        
        for (int j = 2*n-1; j >= 0; j--)
        {
            while(!s.empty() && nums[s.top()] <= nums[j%n])
            {
                s.pop();
            }
            if (s.empty())
            {
                nums_next_gre[j%n] = -1;
            }
            else
            {
                nums_next_gre[j%n] = nums[s.top()];
            }
            s.push(j%n);
        }
        
        return nums_next_gre;
    }
};