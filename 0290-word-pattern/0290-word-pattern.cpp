class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string> mp;
        unordered_map<string,char> rev;
        int st=0;
        for(int i=0;i<pattern.size();i++){
            if(st>=s.size()) return false;
            int end;
            for(end=st;end<s.size();end++){
                if(s[end]==' ') break;
            }
            string word=s.substr(st,end-st);
            st=end+1;
            if(mp.find(pattern[i])==mp.end()){
                if(rev.find(word)!=rev.end()) return false;
                mp[pattern[i]] = word;
                rev[word]= pattern[i];
            }
            if(mp[pattern[i]]!= word) return false;
        }

        if(st<s.size()) return false;

        return true;
    }
};