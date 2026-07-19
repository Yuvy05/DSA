class Solution {
public:
    int rec(int idx , vector<int>&dp , vector<int>& cost){
        if(idx == 0 or idx == 1 ) return cost[idx] ;
        if(dp[idx] != -1)return dp[idx] ;
        int one = rec(idx-1,dp,cost) ;
        int two = rec(idx-2,dp,cost) ;
        return dp[idx] =cost[idx]+ min(one,two) ;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size() ;
        cost.push_back(0) ;
        vector<int>dp(n+1,-1) ;
        dp[0] = cost[0] ;
        dp[1] = cost[1] ;
        return rec(n , dp , cost) ;
    }
};