class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        // min_len[i] stores the minimum length of a valid subarray ending at or before index i
        const int INF = 1e9;
        vector<int> min_len(n, INF);
        
        int left = 0, current_sum = 0;
        int ans = INF;
        
        for (int right = 0; right < n; ++right) {
            current_sum += arr[right];
            
            // Shrink window from the left if sum exceeds target
            while (current_sum > target && left <= right) {
                current_sum -= arr[left++];
            }
            
            // Found a subarray arr[left..right] with sum == target
            if (current_sum == target) {
                int curr_len = right - left + 1;
                
                // If there is a valid non-overlapping subarray before 'left'
                if (left > 0 && min_len[left - 1] != INF) {
                    ans = min(ans, min_len[left - 1] + curr_len);
                }
                
                // Update min_len for the current end position
                min_len[right] = (right > 0) ? min(min_len[right - 1], curr_len) : curr_len;
            } else {
                if (right > 0) {
                    min_len[right] = min_len[right - 1];
                }
            }
        }
        
        return ans >= INF ? -1 : ans;
    }
};