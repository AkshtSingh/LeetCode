class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int lo=0;
        unordered_map<int,int> mp;
        int n=fruits.size();
        int count=1;
        for(int hi=0;hi<n;hi++){
            mp[fruits[hi]]++;
            if(mp.size()<=2){
                int len=hi-lo+1;
                count=max(len,count);
            }
            while(mp.size()>2){
                mp[fruits[lo]]--;
                if(mp[fruits[lo]]==0){
                    mp.erase(fruits[lo]);
                }
                lo++;
            }
        }
        return count;
    }
};