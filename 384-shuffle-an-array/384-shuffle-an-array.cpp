class Solution {
private:
    vector<int> original;
    vector<int> shuff;
public:
    Solution(vector<int>& nums) {
        original = nums;
        shuff = nums;
    }
    
    vector<int> reset() {
        shuff = original;
        return original;
    }
    
    vector<int> shuffle() {
        for (int i = 0; i < shuff.size(); i++)
        {
            int r = rand()%shuff.size();
            swap(shuff[i], shuff[r]);
        }
        return shuff;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */