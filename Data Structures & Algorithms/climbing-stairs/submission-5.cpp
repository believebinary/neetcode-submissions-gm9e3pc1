#include <cstring>
class Solution {
public:
    int arr[46];
    int solve(int n){
        if(n<0){
            return 0;
        }
        if(n==0){
            return 1;
        }
        if(arr[n]!=-1){
            return arr[n];
        }
        return arr[n] = solve(n-1)+solve(n-2);

    }
    int climbStairs(int n) {
        // memset(arr,-1,sizeof(arr));
        // return solve(n);
        if(n<=2){
            return n;
        }
        vector<int> dp(n+1,0);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        for(int i=3;i<=n;i++){
            dp[i] = dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};
