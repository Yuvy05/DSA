class Solution {
public:
    int rec(int idx , int bs , vector<int>&prices ,vector<vector<int>>&dp){
        // base case 
        if(idx >= prices.size()) return 0 ;
        if(dp[idx][bs] != -1) return dp[idx][bs] ;
        int buy = 0 , sell = 0;
        if(bs == 1){
            buy = max(-prices[idx] + rec(idx+1 , 0 , prices,dp) , 0 + rec(idx+1 , 1 , prices,dp)) ;
        }
        else{
            sell = max(prices[idx] + rec(idx+2 , 1 , prices,dp) , 0 + rec(idx+1 , 0 , prices,dp)) ;
        }
        return dp[idx][bs] =  max(buy,sell) ;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size() , vector<int>(2,-1)) ;
        return rec(0 , 1 , prices,dp) ;
    }
};