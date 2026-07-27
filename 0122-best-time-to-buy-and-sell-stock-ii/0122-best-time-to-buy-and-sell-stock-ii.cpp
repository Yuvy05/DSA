class Solution {
public:
    int rec(int idx , vector<int>&prices , int buyy,vector<vector<int>>&dp){
        // base case
        if(idx == prices.size()) return 0 ;
        if(dp[idx][buyy] != -1) return dp[idx][buyy] ;
        //buy
        int buy =0 , sell = 0 ;
        if(buyy == 1){
            buy = max(-prices[idx] + rec(idx+1 , prices , 0,dp) , 0+ rec(idx+1 , prices , 1,dp)) ;
        }
        else{
            sell = max(prices[idx]+rec(idx+1 , prices ,1,dp) , 0+rec(idx+1 , prices,0,dp))  ;
        }
        return dp[idx][buyy] = max(buy,sell) ;
    }
    int maxProfit(vector<int>& prices) {
        // buy = 1 
        // sell = 0 
        vector<vector<int>>dp(prices.size() , vector<int>(3,-1)) ;
        return rec(0 , prices , 1 ,dp) ;
    }
};