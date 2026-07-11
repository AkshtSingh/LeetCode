class Solution {
public:
    int merge(vector<int>& nums, int lo,int mid,int hi){
        vector<int> temp;
        int left = lo;
        int right= mid+1;
        int cnt=0;
            int j=right;

        for (int i = lo; i <= mid; i++) {
            while (j <= hi && nums[i] > 2LL * nums[j]) {
                j++;
            }
            cnt += (j - (mid + 1));
        }
        
        
        while (left <= mid && right <= hi) {
            if (nums[left] <= nums[right]) {
                temp.push_back(nums[left++]);
            } else {
                temp.push_back(nums[right++]);
            }
        }
        while(left<=mid){
            temp.push_back(nums[left++]);
        }
        while(right<=hi){
            temp.push_back(nums[right++]);
        }

        for(int i =lo;i<=hi;i++){
            nums[i] = temp[i-lo];
        }
        return cnt;
    }



    int mergesort(vector<int>& nums, int lo,int hi){
        int cnt=0;
        if(lo>=hi) return cnt;
        int mid = lo + (hi-lo)/2;
        cnt+= mergesort(nums,lo,mid);
        cnt+= mergesort(nums,mid+1,hi);
        cnt+= merge(nums,lo,mid,hi);

        return cnt;
    }


    int reversePairs(vector<int>& nums) {
        return mergesort(nums,0,nums.size()-1);
    }
};