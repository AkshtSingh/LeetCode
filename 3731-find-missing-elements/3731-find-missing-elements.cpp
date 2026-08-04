class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mini=INT_MAX;
        int maxi=INT_MIN;
        unordered_set<int> arr;
        for(auto n : nums){
            arr.insert(n);
            mini=min(mini,n);
            maxi=max(maxi,n);
        }
        vector<int> ans;
        for(int i=mini;i<=maxi;i++){
            if(arr.find(i)==arr.end()) ans.push_back(i);

        }
        return ans;

    }
};