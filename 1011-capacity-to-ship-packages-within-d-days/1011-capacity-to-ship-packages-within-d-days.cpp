class Solution {
public:
    long long calcDays(vector<int>& weights,int mid,int days){
        int res=0;
        int capacity =mid;
        for(int i=0;i<weights.size();i++){
            if(capacity>=weights[i]){
                capacity-=weights[i];
            }else if(weights[i]>mid){
                return INT_MAX;
            }
            else{
                res++;
                capacity=mid;
                i--;
            }
        }
        cout<<"days:"<<res+1<<endl;
        return res+1;
    }




    int shipWithinDays(vector<int>& weights, int days) {
        int lo=1;
        int hi=0;
        for(auto n:weights){
            hi+=n;
        }
        int sum=hi;

        int res;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            cout<<"mid:"<<mid<<endl;
            if(calcDays(weights,mid,days)<=days){
                res=mid;
                hi=mid-1;
            }else lo=mid+1;

        }
        return res;
    }
};