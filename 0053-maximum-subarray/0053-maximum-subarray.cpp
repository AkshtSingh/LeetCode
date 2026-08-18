class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int bestsum=nums[0];
        int res=nums[0];
        for(int i=1;i<nums.size();i++){
            bestsum=max(bestsum+nums[i],nums[i]);
            res=max(bestsum,res);
        }
        return res;
    }
};