#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = static_cast<int>(s.length());
        if (n <= 1) return s;

        int start = 0;
        int maxLen = 1;

        auto expand = [&](int left, int right) {
            while (left >= 0 && right < n && s[left] == s[right]) {
                int currentLen = right - left + 1;
                if (currentLen > maxLen) {
                    maxLen = currentLen;
                    start = left;
                }
                --left;
                ++right;
            }
        };

        for (int i = 0; i < n; ++i) {
            expand(i, i);     // Odd-length palindromes
            expand(i, i + 1); // Even-length palindromes
        }

        return s.substr(start, maxLen);
    }
};