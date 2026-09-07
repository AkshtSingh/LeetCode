class Solution {
public:
    int distinctSubseqII(string s) {
        int MOD = 1e9 + 7;
        
        // Array to store the number of distinct subsequences ending with each character
        vector<long long> endsWith(26, 0);
        long long total = 0;
        
        for (char c : s) {
            int idx = c - 'a';
            
            // The new subsequences we can form:
            // Append 'c' to all existing subsequences (total) + 1 for 'c' by itself
            // Subtract endsWith[idx] to remove duplicates we've already counted for this character
            long long added = (total + 1 - endsWith[idx]) % MOD;
            
            // Handle negative modulo results in C++
            if (added < 0) {
                added += MOD;
            }
            
            // Update the count of subsequences ending with 'c'
            endsWith[idx] = (endsWith[idx] + added) % MOD;
            
            // Update the total distinct subsequences
            total = (total + added) % MOD;
        }
        
        return total;
    }
};