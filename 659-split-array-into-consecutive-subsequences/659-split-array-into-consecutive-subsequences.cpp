class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int num: nums)
        {
            freq[num]++;
        }
        
        unordered_map<int, int> end;
        
        for (int num: nums)
        {
            if (freq[num] == 0)
            {
                continue;
            }
            
            if (end[num] > 0)
            {
                end[num]--;
                freq[num]--;
                end[num+1]++;
            }
            else if (freq[num] > 0 && freq[num+1] > 0 && freq[num+2] > 0)
            {
                freq[num]--;
                freq[num+1]--;
                freq[num+2]--;
                end[num+3]++;
            }
            else
            {
                return false;
            }
        }
        
        return true;
    }
};