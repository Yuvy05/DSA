class Solution {
public:
    int rec(int idx , int amount , vector<int>&coins , vector<vector<int>>&dp){
        //base case
        if(idx == coins.size()) return 0 ;
        if(amount == 0) return 1 ;
        if(dp[idx][amount] != -1) return dp[idx][amount];
        int pick = 0 , notpick = 0 ;
        //pick 
        if(amount >= coins[idx]){
            pick = rec(idx , amount - coins[idx] , coins,dp) ;
        }
        //not pick
        notpick = rec(idx+1 , amount , coins,dp) ;
        return dp[idx][amount] =  pick+notpick ;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size() , vector<int>(amount+1 , -1)) ;
        return rec(0,amount , coins ,dp) ;
    }
};