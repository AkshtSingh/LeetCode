class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        vector<int> fs(256,0);
        vector<int> ft(256,0);

        for(int i=0;i<s.size();i++){
            fs[s[i]]++;
            ft[t[i]]++;
        }
        for(int i=0;i<256;i++){
            if(fs[i]!=ft[i]) return false;
        }

        return true;
    }
};