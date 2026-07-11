class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int lo=0,hi=n-1;

        while(lo<hi){
            int mid= lo+(hi-lo)/2;
            if((mid==n-1 ||nums[mid]!=nums[mid+1]) &&(mid==0|| nums[mid]!=nums[mid-1])) return nums[mid];

            if(mid%2==0){
                if(nums[mid+1] == nums[mid]) lo=mid+1;
                else hi=mid-1;
            }else{
                if(nums[mid] == nums[mid-1]) lo=mid+1;
                else hi=mid-1;
            }
        }
        return nums[lo];
    }
};