class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        for(auto n : digits){
            ans.push_back(n);
        }
        int n = digits.size()-1;
        if(digits.back()!= 9){
            ans[n] +=1;
            return ans;
        }
        while(n>=0){
            if(ans[n]==9){
                ans[n--] = 0;
                continue;
            }
            ans[n]++;
            break;
        }
        if(n==-1){
            ans.insert(ans.begin(),1);
        }
        return ans;
    }
};