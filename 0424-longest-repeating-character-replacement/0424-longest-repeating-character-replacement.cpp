class Solution {
public:
    int maxfreq(unordered_map<int,int>& map){
        int maxi=INT_MIN;
        for(auto n:map){
            maxi=max(n.second,maxi);
        }
        return maxi;
    }
    int characterReplacement(string s, int k) {
        int lo=0;
        int res=INT_MIN;
        unordered_map<int,int> freq;
        for(int hi=0;hi<s.size();hi++){
            freq[s[hi]]++;
            int maxlen=maxfreq(freq);

            int len=hi-lo+1;

            while(k<len-maxlen){
                freq[s[lo]]--;
                if(freq[s[lo]]==0){
                    freq.erase(s[lo]);
                }
                lo++;
                len=hi-lo+1;
                maxlen=maxfreq(freq);
            }
            res=max(res,len);
        }
        return res;
    }
};