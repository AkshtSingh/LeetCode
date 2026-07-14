class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int lo=0;
        int hi=matrix.size()-1;
        while(lo<=hi){
            int mid= lo+(hi-lo)/2;
            if(matrix[mid][0]>target) hi=mid-1;
            else if(matrix[mid][0]<target) lo=mid+1;
            else return true;
        }
        if(hi==-1) return false;
        int idx=hi;
        lo=0;
        hi=matrix[idx].size()-1;

        while(lo<=hi){
            int mid= lo+(hi-lo)/2;
            if(matrix[idx][mid]>target) hi=mid-1;
            else if(matrix[idx][mid]<target) lo=mid+1;
            else return true;
        }

        return false;
    }
};