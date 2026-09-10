class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto n:nums){
            mp[n]++;
        }
        int res=0;
        int count=0;
        for(auto n: mp){
            if(mp.find(n.first-1)!=mp.end()) continue;
            count=1;
            int curr=n.first;
            while(mp.find(curr+1)!=mp.end()){
                count++;
                curr++;
            }
            res=max(res,count);
        }
        return res;
    }
};