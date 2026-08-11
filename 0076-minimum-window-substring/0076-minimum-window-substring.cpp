class Solution {
public:
    bool haveWhatNeed(vector<int>& need,vector<int>& have){
        for(int i=0;i<256;i++){
            if(need[i]>have[i]) return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        int lo=0;
        vector<int> need(256,0);
        vector<int> have(256,0);
        for(auto ch:t){
            need[ch]++;
        }
        int flag=0;
        int res=INT_MAX;
        int start=0;
        for(int hi=0;hi<s.size();hi++){
            have[s[hi]]++;
            
            while(haveWhatNeed(need,have)){
                flag=1;
                int len=hi-lo+1;
                if(res>len){  
                res=len;
                start=lo;
                }
                have[s[lo]]--;
                lo++;
            }
                
        }
        if(!flag) return "";
        return s.substr(start,res);

    }
};