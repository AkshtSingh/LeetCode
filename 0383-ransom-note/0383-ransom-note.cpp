class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> have(256,0);
        vector<int> req(256,0);

        for(auto ch:magazine){
            have[ch]++;
        }
        for(auto ch:ransomNote){
            req[ch]++;
        }
        for(int i=0;i<256;i++){
           
            if(req[i]>have[i]) return false;
        }
        return true;
    }
};