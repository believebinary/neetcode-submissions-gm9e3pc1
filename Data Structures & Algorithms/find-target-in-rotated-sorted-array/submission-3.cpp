class Solution {
public:
    int search(vector<int>& nums, int target) {
        int right = nums.size()-1;
        int left = 0;
        int pivotIndex = 0;
        while(left<right){
            int mid = left + (right-left)/2;
            if(nums[mid]>nums[right]){
                left = mid+1;
            }
            else {
                right = mid;
            }
        }
        pivotIndex = right;
        left =0;
        right = pivotIndex-1;
        while(left<=right){
            int mid = left + (right-left)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>target){
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        left = pivotIndex;
        right = nums.size()-1;
        while(left<=right){
            int mid = left + (right-left)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>target){
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }

        return -1;
        
    }
};
