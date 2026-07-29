class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int ans=w;
        vector<pair<int,int>> arr;
        for(int i=0;i<profits.size();i++){
            pair<int,int> p={capital[i],profits[i]};
            arr.push_back(p);
        }

        sort(arr.begin(),arr.end());

        int idx=0;
        priority_queue<int> pq;
        for(int i=0;i<k;i++){
            for(idx;idx<arr.size();idx++){
                if(arr[idx].first<=ans){ pq.push(arr[idx].second);}
                else{ break;}
            }
            if(pq.empty()){
                break;
            }
            cout<<pq.top()<<endl;
            ans+=pq.top();
            pq.pop();
            
        }
        return ans;
    }
};