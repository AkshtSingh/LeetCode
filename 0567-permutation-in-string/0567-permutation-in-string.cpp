class Solution {
public:
    bool contains(vector<int>& need,vector<int>& have){
        for(int i=0;i<256;i++){
            if(need[i]>have[i]) return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int lo=0;
        vector<int> need(256,0);
        vector<int> have(256,0);
        for(auto ch:s1){
            need[ch]++;
        }
        for(int hi=0;hi<s2.size();hi++){
            have[s2[hi]]++;
            while(contains(need,have)){
                int len=hi-lo+1;
                if(len==s1.size()){
                    return true;
                }
                have[s2[lo]]--;
                lo++;
            }
        }
        return false;
    }
};