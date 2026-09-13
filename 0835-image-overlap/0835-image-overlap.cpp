class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int, int>> v1, v2;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (img1[i][j] == 1) v1.push_back({i, j});
                if (img2[i][j] == 1) v2.push_back({i, j});
            }
        }

        // Shift offsets range from -(n-1) to (n-1)
        // Map offset (dr, dc) to a 2D frequency array with index shifted by +n
        int count[60][60] = {0};
        int maxOverlap = 0;

        for (const auto& [r1, c1] : v1) {
            for (const auto& [r2, c2] : v2) {
                int dr = r1 - r2 + n;
                int dc = c1 - c2 + n;
                count[dr][dc]++;
                maxOverlap = max(maxOverlap, count[dr][dc]);
            }
        }

        return maxOverlap;
    }
};