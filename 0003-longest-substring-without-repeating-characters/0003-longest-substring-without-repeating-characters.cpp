class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int lo=0;
        
        int count=0;
        for(int hi=0;hi<s.size();hi++){
            
            while(mp.find(s[hi])!= mp.end()){
                mp[s[lo]]--;
                if(mp[s[lo]]==0){
                    mp.erase(s[lo]);
                }
                lo++;
                

            }
            
            mp[s[hi]]++;
            int len=hi-lo+1;
            count = max(len,count);
            
        }
        return count;
    }
};