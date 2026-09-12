#include <vector>
#include <array>
#include <algorithm>

using namespace std;

class Solution {
    struct Interval {
        int l, r, weight, id;
    };

    struct State {
        long long weight = 0;
        vector<int> indices;

        // Custom comparator:
        // 1. Maximize total weight.
        // 2. Minimize lexicographical order of the sorted indices.
        bool operator<(const State& other) const {
            if (weight != other.weight) {
                return weight < other.weight;
            }
            return indices > other.indices; // smaller indices vector is considered "better" (larger)
        }
    };

public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<Interval> arr(n);
        for (int i = 0; i < n; ++i) {
            arr[i] = {intervals[i][0], intervals[i][1], intervals[i][2], i};
        }

        // Sort intervals primarily by right endpoint 'r'
        sort(arr.begin(), arr.end(), [](const Interval& a, const Interval& b) {
            if (a.r != b.r) return a.r < b.r;
            return a.l < b.l;
        });

        // dp[k][i]: best state picking k intervals using a subset of the prefix arr[0...i-1]
        vector<vector<State>> dp(5, vector<State>(n + 1));

        for (int i = 1; i <= n; ++i) {
            int l = arr[i - 1].l;
            int w = arr[i - 1].weight;
            int orig_id = arr[i - 1].id;

            // Find the largest index j (0-indexed) such that arr[j].r < l
            // Binary search over arr[0 ... i-2]
            int low = 0, high = i - 2, prev_idx = 0;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (arr[mid].r < l) {
                    prev_idx = mid + 1; // 1-based index in dp table
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }

            for (int k = 1; k <= 4; ++k) {
                // Option 1: Do not pick the current interval arr[i - 1]
                dp[k][i] = dp[k][i - 1];

                // Option 2: Pick the current interval arr[i - 1]
                if (k == 1) {
                    State take;
                    take.weight = w;
                    take.indices = {orig_id};
                    if (dp[k][i] < take) {
                        dp[k][i] = take;
                    }
                } else if (dp[k - 1][prev_idx].weight > 0 || prev_idx == 0) {
                    if (dp[k - 1][prev_idx].weight > 0) {
                        State take;
                        take.weight = dp[k - 1][prev_idx].weight + w;
                        take.indices = dp[k - 1][prev_idx].indices;
                        take.indices.push_back(orig_id);
                        sort(take.indices.begin(), take.indices.end());

                        if (dp[k][i] < take) {
                            dp[k][i] = take;
                        }
                    }
                }
            }
        }

        // Find the best state across 1, 2, 3, or 4 chosen intervals
        State best;
        for (int k = 1; k <= 4; ++k) {
            if (best < dp[k][n]) {
                best = dp[k][n];
            }
        }

        return best.indices;
    }
};