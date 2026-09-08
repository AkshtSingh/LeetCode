class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> lastSeenS(256,-1);
        vector<int> lastSeenT(256,-1);

        for(int i =0;i<s.size();i++){
            if(lastSeenS[s[i]]==-1&&lastSeenT[t[i]]==-1){
                lastSeenS[s[i]]=i;
                lastSeenT[t[i]]=i;
            }else if(lastSeenS[s[i]]!=lastSeenT[t[i]]){
                return false;
            }
        }
        return true;
    }
};