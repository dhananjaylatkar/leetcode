class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int sum = ((n+1)*(n))/2;
        int duplicate = -1;
        unordered_set<int> s;
        
        for (int num: nums)
        {
            if (s.find(num) != s.end())
            {
                duplicate = num;
            }
            s.insert(num);
            sum -= num;
        }
        
        return {duplicate, sum+duplicate};
    }
};