class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size());
        int start =1;

        for(int i =0;i<nums.size();i++){
            ans[i] = start;
            start = nums[i]*start;
        }
        start = 1;
        for(int j = nums.size()-1; j>=0; j--){
            ans[j] = ans[j]*start;
            start = nums[j]*start;
        }
        return ans;
    }
};
