class Solution {
public:
    int maxArea(vector<int>& height) {
        int left =0,right=height.size()-1;
        int maxarea=0;
        while(left<right){
            int mini=min(height[left],height[right]);
            int area=mini*(right-left);
            maxarea=max(area,maxarea);
            if(height[left]<height[right]) left++;
            else right--;

        }

        return maxarea;
    }
};