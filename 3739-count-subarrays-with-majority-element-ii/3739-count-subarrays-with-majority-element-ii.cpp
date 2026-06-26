class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        
        int offset = n + 1;
        int treeSize = 2 * n + 2;
        vector<int> bit(treeSize, 0);
        
        auto update = [&](int idx, int val) {
            for (; idx < treeSize; idx += idx & -idx) {
                bit[idx] += val;
            }
        };
        
        auto query = [&](int idx) {
            long long sum = 0;
            for (; idx > 0; idx -= idx & -idx) {
                sum += bit[idx];
            }
            return sum;
        };
        
        long long totalSubarrays = 0;
        int currentPrefixSum = 0;
        
        update(0 + offset, 1);
        
        for (int num : nums) {
            if (num == target) {
                currentPrefixSum += 1;
            } else {
                currentPrefixSum -= 1;
            }
            
            totalSubarrays += query(currentPrefixSum + offset - 1);
            
            update(currentPrefixSum + offset, 1);
        }
        
        return totalSubarrays;
    }
};