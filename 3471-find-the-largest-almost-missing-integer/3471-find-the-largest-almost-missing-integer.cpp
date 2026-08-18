class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> mp;

        if(k==1){
            int res=-1;
            for(auto n: nums){
                mp[n]++;
            } 
            for(auto p:mp){
                if(p.second==1) res=max(res,p.first);
            }  
            return res;
        }else if(k==n){
            int res=-1;
            for(auto n: nums){
                res=max(res,n);
            }
            return res;
        }else{
            for(auto n:nums){
                mp[n]++;
            }
            if(mp[nums[0]]==1&&mp[nums[n-1]]==1){
                return max(nums[0],nums[n-1]);
            }else if(mp[nums[0]]==1){
                return nums[0];
            }else if(mp[nums[n-1]]==1){
                return nums[n-1];
            }
        }
        return -1;
        
    }
};