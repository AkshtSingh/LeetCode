class Solution {
public:
    long long sumofdiv(vector<int>& nums,int mid,int threshold){
        long long sum =0;
        for(auto n:nums){
            if(n%mid==0){
                sum+=((long long)n/mid);
            }else{
                sum+=((long long)n/mid +1);
            }
        }
        return sum;
    }


    int smallestDivisor(vector<int>& nums, int threshold) {
        int lo=1;
        int hi=INT_MIN;
        int res=1;
        for(auto n:nums){
            hi=max(hi,n);
        }

        while(lo<=hi){
            int mid=lo+(hi-lo)/2;

            if(sumofdiv(nums,mid,threshold)<=threshold){
                res=mid;
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }

        return res;

    }
};