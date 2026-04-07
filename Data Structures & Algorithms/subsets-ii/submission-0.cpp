class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int>& nums, int idx, vector<int>& temp){
        if(idx>nums.size()-1){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[idx]);
        solve(nums,idx+1,temp);
        temp.pop_back();
        while(idx+1<nums.size() && nums[idx+1]==nums[idx]) idx++;
        solve(nums,idx+1,temp);
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        sort(begin(nums),end(nums));
        solve(nums,0,temp);
        return ans;
    }
};
