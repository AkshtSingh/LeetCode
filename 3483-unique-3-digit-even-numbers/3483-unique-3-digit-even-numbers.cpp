class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> count(10, 0);
        for (int d : digits) {
            count[d]++;
        }

        int ans = 0;
        // Check every 3-digit even number
        for (int num = 100; num <= 998; num += 2) {
            int d1 = num / 100;
            int d2 = (num / 10) % 10;
            int d3 = num % 10;

            vector<int> needed(10, 0);
            needed[d1]++;
            needed[d2]++;
            needed[d3]++;

            if (needed[d1] <= count[d1] && 
                needed[d2] <= count[d2] && 
                needed[d3] <= count[d3]) {
                ans++;
            }
        }

        return ans;
    }
};