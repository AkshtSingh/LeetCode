class Solution {
public:
    long long calcTime(vector<int>& piles,int k){
        long long time=0;
        for(auto pile: piles){
            if(pile%k==0){
                time+=((long long) pile/k);
            }else{
                time+=((long long)pile/k +1);
            }
        }
        return time;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int hi= INT_MIN;
        for(auto pile:piles){
            hi= max(hi,pile);
        }
        int k;

        int lo=1;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            long long time=calcTime(piles,mid);
            if(time>h) lo= mid+1;
            else {
                k=mid;
                hi=mid-1;
            }
            
        }
        return k;
    }
};