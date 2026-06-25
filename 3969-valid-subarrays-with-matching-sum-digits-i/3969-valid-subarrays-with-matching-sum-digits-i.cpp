class Solution {
public:
    int countValidSubarrays(vector<int>& nums, int x) {
        int count = 0;
        int n=nums.size();

        for(int i = 0;i<n;++i){
            long long currsum = 0;
            for(int j = i;j<n;++j){
                currsum += nums[j];

                if(currsum %10 ==x){
                    long long temp = currsum;
                    while(temp>=10){
                        temp/=10;
                        
                    }

                    if(temp==x){
                        count++;
                    }

                    
                }
            }
        }
        return count;
    }
};