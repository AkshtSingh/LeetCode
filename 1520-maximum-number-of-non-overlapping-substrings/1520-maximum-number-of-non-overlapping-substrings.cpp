#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.length();
        vector<int> first(26, n), last(26, -1);

        for (int i = 0; i < n; ++i) {
            int c = s[i] - 'a';
            first[c] = min(first[c], i);
            last[c] = max(last[c], i);
        }

        vector<pair<int, int>> intervals; // {right, left} for easy sorting by end

        for (int i = 0; i < 26; ++i) {
            if (first[i] == n) continue;

            int l = first[i];
            int r = last[i];
            bool valid = true;

            for (int j = l; j <= r; ++j) {
                int c = s[j] - 'a';
                // If a character inside has an occurrence before 'l',
                // any valid range covering it must start <= first[c] < l,
                // so no minimal valid range starts at 'l'.
                if (first[c] < l) {
                    valid = false;
                    break;
                }
                r = max(r, last[c]);
            }

            if (valid) {
                intervals.push_back({r, l});
            }
        }

        // Sort by end index ascending
        sort(intervals.begin(), intervals.end());

        vector<string> result;
        int prev_end = -1;

        for (const auto& [r, l] : intervals) {
            if (l > prev_end) {
                result.push_back(s.substr(l, r - l + 1));
                prev_end = r;
            }
        }

        return result;
    }
};