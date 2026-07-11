class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n= nums.size();
        int hi=n-1;
        int lo=0;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(nums[mid]>target){
                hi= mid-1;
            }else if(nums[mid]<target){
                lo=mid+1;
            }else{
                return mid;
            }
        }
        return -1;
    }
};