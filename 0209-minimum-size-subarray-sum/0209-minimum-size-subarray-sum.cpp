class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int hi=0,lo=0;
        int n=nums.size();
        int sum=0,count=INT_MAX;
        for(hi=0;hi<n;hi++){
            sum+=nums[hi];
            while(sum>=target){
                count=min(count,hi-lo+1);
                sum-=nums[lo];
                lo++;
            }
            
        }
        if(count==INT_MAX) return 0;
        return count;
    }
};