class Solution {
public:
    int search(vector<int>& arr, int target) {
        int n = arr.size();
        int low = 0;
        int high = n-1;
        
        while (low <= high)
        {
            int mid = ((low - high) / 2) + high;
            if (arr[mid] == target) return mid;
            if (arr[low] < arr[mid])
            {
                if (target >= arr[low] && target < arr[mid])
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            else
            {
                if (mid+1 < n && target >= arr[mid + 1] && target <= arr[high])
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};