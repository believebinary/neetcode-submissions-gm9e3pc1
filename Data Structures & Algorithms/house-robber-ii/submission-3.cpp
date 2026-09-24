#include <string.h>
class Solution {
public:
    int dp[101];
    int solve(int n, vector<int>& nums, int idx){
        if(idx > n){
            return 0;
        }
        // if(idx == n-1){
        //     return nums[idx];
        // }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        int take = nums[idx] + solve(n,nums,idx+2);
        int skip = solve(n,nums,idx+1);
        return dp[idx] = max(take,skip);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        memset(dp,-1,sizeof(dp));
        if(n==1){
            return nums[0];
        }
        if(n==2){
            return max(nums[0],nums[1]);
        }
        int first = solve(n-1,nums,1);
         memset(dp,-1,sizeof(dp));
        int second = solve(n-2,nums,0);
        return max(first,second);
    }
};
