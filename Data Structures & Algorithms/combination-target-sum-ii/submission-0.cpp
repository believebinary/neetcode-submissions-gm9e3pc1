class Solution {
public:
    void solve(vector<int>& candidates, vector<int>& temp, vector<vector<int>>& ans, int target, int idx){
        if(target<0){
            return;
        }
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        for(int i =idx;i<candidates.size();i++){
            if(i>idx && candidates[i]==candidates[i-1]){
                continue;
            }
            temp.push_back(candidates[i]);
            solve(candidates,temp,ans,target-candidates[i],i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(begin(candidates),end(candidates));
        solve(candidates,temp,ans,target,0);
        return ans;
    }
};
