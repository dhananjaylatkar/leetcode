class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        
        vector<int> res;
        
        for (auto q: queries)
        {
            int count = 0;
            
            for (auto n: nums)
            {
                if (q >= n)
                {
                    q -= n;
                    count++;
                }
                else break;
            }
            
            res.push_back(count);
        }
        
        return res;
    }
};