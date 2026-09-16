class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.length();
        int ans = 0;
        int last_end = -1; // End index of the last chosen palindrome

        // Expand around center to find palindromes of length k or k + 1
        // There are 2*n - 1 possible centers
        for (int center = 0; center < 2 * n - 1; ++center) {
            int l = center / 2;
            int r = l + (center % 2);

            while (l >= 0 && r < n && s[l] == s[r]) {
                int len = r - l + 1;
                if (len >= k) {
                    if (l > last_end) {
                        ans++;
                        last_end = r;
                        break; // Greedily take this shortest valid palindrome
                    }
                }
                l--;
                r++;
            }
        }

        return ans;
    }
};