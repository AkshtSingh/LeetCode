class Solution {
public:
    int numberOfSets(int n, int k) {
        long long MOD = 1e9 + 7;
        int total = n + k - 1;
        int r = 2 * k;

        if (r > total) return 0;

        // Compute C(total, r) % MOD
        // C(N, R) = N! / (R! * (N - R)!)
        auto power = [&](long long base, long long exp) -> long long {
            long long res = 1;
            base %= MOD;
            while (exp > 0) {
                if (exp % 2 == 1) res = (res * base) % MOD;
                base = (base * base) % MOD;
                exp /= 2;
            }
            return res;
        };

        auto modInverse = [&](long long n) -> long long {
            return power(n, MOD - 2);
        };

        long long num = 1, den = 1;
        for (int i = 0; i < r; ++i) {
            num = (num * (total - i)) % MOD;
            den = (den * (i + 1)) % MOD;
        }

        return (num * modInverse(den)) % MOD;
    }
};