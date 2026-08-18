class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxsum=nums[0];
        int minsum=nums[0];
        int maxres=nums[0];
        int sumarr=nums[0];
        int minres=nums[0];
        for(int i=1;i<nums.size();i++){
            maxsum=max(maxsum+nums[i],nums[i]);
            minsum=min(minsum+nums[i],nums[i]);
            maxres=max(maxres,maxsum);
            minres=min(minres,minsum);
            sumarr+=nums[i];
        }
        
        if(maxres<0){
            return maxres;
        }
        
        return max(maxres,sumarr-minres);
    }
};