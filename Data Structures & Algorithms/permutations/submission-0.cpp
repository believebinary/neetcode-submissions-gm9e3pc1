class Solution {
public:
    vector<vector<int>> ans;
    unordered_set<int> s;
    void solve(vector<int>& nums , vector<int>& temp){
        if(temp.size() == nums.size()){
            ans.push_back(temp);
            return;
        }
        for(int i =0;i<nums.size();i++){
            if(s.find(nums[i])==s.end()){
                temp.push_back(nums[i]);
                s.insert(nums[i]);
                solve(nums,temp);
                temp.pop_back();
                s.erase(nums[i]);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;

        solve(nums,temp);
        return ans;
    }
};
