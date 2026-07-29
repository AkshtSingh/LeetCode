class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>,greater<int>> pq;
        int i=0;
        for(auto n:nums){
            if(i<k){
                pq.push(n);
                i++;
                continue;
            }
            if(n>pq.top()){
                pq.pop();
                pq.push(n);
            }

        }
        return pq.top();
    }
};