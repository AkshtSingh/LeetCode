class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans="";
        int level=0;
        for(auto ch:s){
            if(ch=='(') {
                level++;
                if(level>1){
                    ans+="(";
                }
            }
            if(ch==')'){
                level--;
                if(level>0){
                    ans+=")";
                }
            }
        }

        return ans;
    }
};