class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int nodelete=arr[0];
        int onedelete = arr[0];
        int res=arr[0];
        for(int i=1;i<arr.size();i++){
            int prevnodelete=nodelete;
            int prevdelete=onedelete;
            nodelete=max({prevnodelete+arr[i],arr[i]});
            onedelete=max(prevdelete+arr[i],prevnodelete);
            res=max({nodelete,onedelete,res});
        }
        return res;
    }
};