class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> m;
        
        for (int j = 0; j < nums2.size(); j++)
        {
            m[nums2[j]] = j;
        }
        
        stack<int> s;
        int n = nums2.size();
        vector<int> nums2_next_gre(n);
        s.push(nums2[n-1]);
        nums2_next_gre[n-1] = -1;
        
        for (int j = n-2; j >= 0; j--)
        {
            while(!s.empty() && s.top() < nums2[j])
            {
                s.pop();
            }
            if (s.empty())
            {
                nums2_next_gre[j] = -1;
            }
            else
            {
                nums2_next_gre[j] = s.top();
            }
            s.push(nums2[j]);
        }
        
        vector<int> res;
        
        for (int i = 0; i<nums1.size(); i++)
        {
            res.push_back(nums2_next_gre[m[nums1[i]]]);
        }
        return res;
    }
};