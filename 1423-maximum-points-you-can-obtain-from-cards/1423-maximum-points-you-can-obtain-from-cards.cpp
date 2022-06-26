class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum = 0;
        int n = cardPoints.size();
        for (int i = 0; i < n-k; i++)
        {
            sum += cardPoints[i];
        }
        // cout << sum << endl;
        
        int total_sum = sum;
        
        for (int i = n-k; i < n; i++)
        {
            total_sum += cardPoints[i];
        }

        int min_sum = sum;
        
        int l = 0;
        int r = n-k;
        
        while (r < n)
        {
            sum -= cardPoints[l];
            sum += cardPoints[r];
            // cout << sum << endl;
            l++; r++;
            min_sum = min(min_sum, sum);
        }
        
        return total_sum - min_sum;
    }
};