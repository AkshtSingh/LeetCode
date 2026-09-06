class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k=0;
        for(auto n:nums){
            if(k<2||n>nums[k-2]){
                nums[k]= n;
                k++;
            }
        }
        
        return k;
    }
};