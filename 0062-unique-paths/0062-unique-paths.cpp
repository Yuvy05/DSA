class Solution {
public:
    int rec(int i , int j , vector<vector<int>>&dp){
        // base case
        if(i == 0 and j == 0) return 1 ;
        if(dp[i][j] != -1) return dp[i][j] ;
        int up = 0 , left = 0 ;
        //up
        if(i -1 >= 0)
         up = rec(i-1 , j,dp ) ;

        //left
        if(j-1 >= 0)
         left = rec(i , j-1 ,dp) ;
        
        return dp[i][j] = up+left ;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m , vector<int>(n, - 1)) ;
        return rec(m-1,n-1 , dp) ;
    }
};