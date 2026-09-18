#include <string.h>
class Solution {
public:
    int dp[101];
    int solve(vector<int>& cost, int idx, int n){
        if(idx >= n){
            return 0;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        return dp[idx]=               cost[idx]+min(solve(cost,idx+1,n),solve(cost,idx+2,n));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        memset(dp,-1,sizeof(dp));
        return min(solve(cost,0,n),solve(cost,1,n));
    }
};
