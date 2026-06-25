class Solution {
public:
    int maxTotalValue(vector<int>& value, vector<int>& decay, int m) {
        long long low = 1, high = 0;
        for (int v : value) {
            if (v > high) high = v;
        }
        
        
        auto count_picks = [&](long long x) {
            long long cnt = 0;
            for (int i = 0; i < value.size(); ++i) {
                if (value[i] >= x) {
                    cnt += (value[i] - x) / decay[i] + 1;
                }
            }
            return cnt;
        };
        
        
        long long opt_x = 0;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (count_picks(mid) >= m) {
                opt_x = mid;
                low = mid + 1; 
            } else {
                high = mid - 1;
            }
        }
        
        long long total_sum = 0;
        long long total_picks = 0;
        long long MOD = 1e9 + 7;
        
       
        long long threshold = opt_x + 1;
        for (int i = 0; i < value.size(); ++i) {
            if (value[i] >= threshold) {
                long long k = (value[i] - threshold) / decay[i] + 1;
                total_picks += k;
                
                long long v = value[i];
                long long d = decay[i];
                
               
                long long term1 = (k % MOD) * (v % MOD) % MOD;
                long long pairs = (k * (k - 1) / 2) % MOD;
                long long term2 = (d % MOD) * pairs % MOD;
                
                long long sum_i = (term1 - term2 + MOD) % MOD;
                total_sum = (total_sum + sum_i) % MOD;
            }
        }
        
       
        long long rem = m - total_picks;
        if (opt_x > 0 && rem > 0) {
            long long rem_sum = (rem % MOD) * (opt_x % MOD) % MOD;
            total_sum = (total_sum + rem_sum) % MOD;
        }
        
        return total_sum;
    }
};