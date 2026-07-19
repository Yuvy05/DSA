class Solution {
public:
    int dfs(int idx , int n , vector<int>&dp){
        if(idx == 0 or idx == 1){
            return 1 ;
        }
        if(dp[idx] != 0) return dp[idx] ;
        int left = dfs(idx-1,n,dp) ;
        int right = dfs(idx-2,n,dp) ;
        return dp[idx] = left+right ;
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,0) ;
        return dfs(n,n,dp) ;
    }
};