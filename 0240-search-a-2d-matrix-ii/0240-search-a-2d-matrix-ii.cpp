class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        int row=0,col=cols-1;
        while(row<rows && row>=0 &&col<cols && col>=0){
            cout<<matrix[row][col]<<endl;
            if(matrix[row][col]<target) row++;
            else if(matrix[row][col]>target) col--;
            else return true;
        }
        return false;
    }
};