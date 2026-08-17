class Solution {
public:
    int next(int n){
        int sum=0;
        while(n>0){
            int rem=n%10;
            n/=10;
            sum+=(rem*rem);
        }
        return sum;
    }
    bool isHappy(int n) {
        int slow=n,fast=n;
        while(fast!=1){
            slow=next(slow);
            fast=next(next(fast));
            if(fast!=1&&fast==slow){
                return false;
            }
        }
        return true;
    }
};