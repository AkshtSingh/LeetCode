class Solution {
public:
    string largestOddNumber(string num) {
        int endidx=num.size()-1;
        int stidx=0;
        while(endidx>=0){
            cout<<num[endidx]<<endl;
            if(((num[endidx]-'0')%2)==0){
                endidx--;
            }else{
                break;
            }
            
        }
        if(endidx==-1) return "";
        while(stidx<=endidx){
            if(num[stidx]=='0'){
                stidx++;
            }else{
                break;
            }
        }
        return num.substr(stidx,endidx-stidx+1);
    }
};