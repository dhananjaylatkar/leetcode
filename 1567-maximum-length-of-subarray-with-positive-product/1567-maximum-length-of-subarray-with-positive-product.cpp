class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int res = 0;

        int n = nums.size();
        int i = 0;
        while (i < n)
        {
            int start = i;
            while (i < n && nums[i] == 0)
            {
                start++;
                i++;
            }
            int negs = 0;
            int first = 0;
            bool updated_first = false;
            int last = 0;
            int end = start;
            
            while (end < n && nums[end] != 0)
            {
                if (nums[end] < 0)
                {
                    negs++;
                    if (!updated_first) 
                    {
                        first = end;
                        updated_first = true;
                    }
                    last = end;
                }
                end++;
            }
            
            i = end + 1;
            // cout << first << " " << last << endl;
            if (negs%2 == 0)
            {
                res = max(res, end-start);
            }
            else
            {
                res = max(res, max(last-start, end-first-1));
            }
        }
        return res;
    }
};