class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int minsum=nums[0];
        int maxsum=nums[0];
        int res=abs(nums[0]);
        for(int i=1;i<nums.size();i++){
            int prevmax=maxsum;
            int prevmin=minsum;
            maxsum=max(prevmax+nums[i],nums[i]);
            minsum=min(prevmin+nums[i],nums[i]);
            if(minsum<0){

            res=max({maxsum,-minsum,res});
            }
            res=max({maxsum,minsum,res});

        }
        return res;
    }
};