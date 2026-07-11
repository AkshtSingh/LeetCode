class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int last = nums[n-1];
        int lo=0,hi=n-1;

        while(lo<=hi){
            int mid = lo+(hi-lo)/2;

            if(nums[mid]>last) lo=mid+1;
            else hi=mid-1;
        }

        return nums[lo];
    }
};