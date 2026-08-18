class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxprod=nums[0];
        int minprod=nums[0];
        int res=nums[0];
        for(int i=1;i<nums.size();i++){
            int prevmax=maxprod;
            int prevmin=minprod;
            maxprod=max({prevmax*nums[i],nums[i],prevmin*nums[i]});
            minprod=min({prevmin*nums[i],prevmax*nums[i],nums[i]});
            res=max({res,maxprod,minprod});
        }
        return res;
    }
};