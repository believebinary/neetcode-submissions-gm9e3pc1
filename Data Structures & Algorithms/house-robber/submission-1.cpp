#include <string.h>
class Solution {
public:
    int dp[101];
    int solve(int n, vector<int>& nums, int idx){
        if(idx >=n){
            return 0;
        }
        if(idx==n-1){
            return nums[idx];
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        return dp[idx] = nums[idx] + max(solve(n,nums,idx+2),solve(n,nums,idx+3));
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        memset(dp,-1,sizeof(dp));
        return max(solve(n,nums,0),solve(n,nums,1));
    }
};
