class Solution {
public:
    void swap(vector<int>& nums, int n, int m){
        int temp = nums[n];
        nums[n] = nums[m];
        nums[m] = temp;
    }
    void sortColors(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        int mid = 0;
        while(mid<=right){
            if(nums[mid] == 0){
               swap(nums,mid++,left++);
            }
            else if(nums[mid] == 1){
                mid++;                
            }
            else{
                swap(nums,mid,right--);
                

            }
            
        }
    }
};