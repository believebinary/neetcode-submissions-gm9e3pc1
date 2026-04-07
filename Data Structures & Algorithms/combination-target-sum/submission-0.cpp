class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int>& nums, int target,vector<int>& temp,int start){
       
        if(start>nums.size()-1){
            if(target==0){
                ans.push_back(temp);
            }
            return;
        }
        if(target>=nums[start]){
           temp.push_back(nums[start]);
           solve(nums,target-nums[start],temp,start);
           temp.pop_back();
        }
        solve(nums,target,temp,start+1);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> temp;
        int sum = 0;
        solve(nums,target,temp,0);
        return ans;
    }
};
