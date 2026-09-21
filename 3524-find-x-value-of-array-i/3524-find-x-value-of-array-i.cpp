#include <vector>

class Solution {
public:
    std::vector<long long> resultArray(std::vector<int>& nums, int k) {
        std::vector<long long> result(k, 0);
        std::vector<long long> dp(k, 0);

        for (int x : nums) {
            std::vector<long long> next_dp(k, 0);
            int m = x % k;

            // Subarray consisting solely of nums[i]
            next_dp[m]++;

            // Extend existing subarrays ending at the previous index
            for (int r = 0; r < k; ++r) {
                if (dp[r] > 0) {
                    int new_rem = (r * m) % k;
                    next_dp[new_rem] += dp[r];
                }
            }

            // Accumulate to total answer
            for (int r = 0; r < k; ++r) {
                result[r] += next_dp[r];
            }

            dp = std::move(next_dp);
        }

        return result;
    }
};