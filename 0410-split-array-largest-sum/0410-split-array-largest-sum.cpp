class Solution {
public:
    int possible(vector<int> & nums,int sum){
        int subarr=1;
        int currsum=0;
        for(auto n:nums){
            if(currsum+n<=sum){
                currsum+=n;
            }else{
                subarr++;
                currsum=n;
            }
        }
        return subarr;
    }





    int splitArray(vector<int>& nums, int k) {
        int lo=INT_MIN;
        int hi=0;
        for(auto n:nums){
            lo=max(lo,n);
            hi+=n;
        }
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            int subarr =possible(nums,mid);
            if(subarr>k){
                lo=mid+1;
            }else{
                hi= mid-1;
            }
        }
        return lo;
    }
};