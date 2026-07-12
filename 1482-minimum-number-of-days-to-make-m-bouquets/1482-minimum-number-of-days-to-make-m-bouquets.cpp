class Solution {
public:
    bool possible(vector<int>& arr, int day,int m,int k){
        int cnt=0,bouquets=0;
        for(int i =0;i<arr.size();i++){
            if(arr[i]<=day){
                cnt++;
                if(cnt==k){
                    bouquets++;
                    cnt=0;
                }
            }else{
                cnt=0;
            }
        }
        return bouquets>=m;
    }



    int minDays(vector<int>& bloomDay, int m, int k) {
        long long total = 1LL*m*k;
        if(total>bloomDay.size()) return -1;
        int hi=INT_MIN;
        int lo=INT_MAX;
        int day=-1;
        for(auto b:bloomDay){
            hi=max(hi,b);
            lo=min(lo,b);
        }

        while(lo<=hi){
            int mid=lo+(hi-lo)/2;

            if(possible(bloomDay,mid,m,k)){
                day=mid;
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }
        return day;
    }
};