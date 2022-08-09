#define MOD 1000000007
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        unordered_map<int, long long int> m;
        
        for (int num: arr)
        {
            m[num] = 1;
        }
        
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (arr[i]%arr[j] == 0 && m.find(arr[i]/arr[j]) != m.end())
                {
                    m[arr[i]] += m[arr[j]] * m[arr[i]/arr[j]];
                }
            }
        }
        long long int res = 0;
        for (auto it: m)
        {
            res += it.second;
        }
        return res%MOD;
    }
};