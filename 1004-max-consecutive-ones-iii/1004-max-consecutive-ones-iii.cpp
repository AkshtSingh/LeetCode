class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int lo=0;
        int res=INT_MIN;
        int zeros=0;
        for(int hi=0;hi<nums.size();hi++){
            if(nums[hi]==0) zeros++;
            while(zeros>k){
                if(nums[lo]==0){
                    zeros--;
                }
                lo++;
            }
            int len=hi-lo+1;
            res=max(len,res);
        }
        return res;
    }
};