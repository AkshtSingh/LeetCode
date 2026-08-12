class Solution {
public:
    
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        int lo=0;
        int res=INT_MIN;

        for(int hi=0;hi<nums.size();hi++){
            freq[nums[hi]]++;
            while(freq[nums[hi]]>k){
                freq[nums[lo]]--;
                lo++;
            }
            int len=hi-lo+1;
            res=max(len,res);
        }
        return res;
    }
};