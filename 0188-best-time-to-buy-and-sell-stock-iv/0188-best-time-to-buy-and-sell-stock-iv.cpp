class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>>dp(prices.size() +1, vector<vector<int>>(2 , vector<int>(k+1 ,0 )));

        // for converting into tabulation
        // -> copy base case
        // -> reverse the condition for looping compared to memoization
        // -> copy the recurrence call
        for(int idx = prices.size() - 1 ; idx >= 0 ; idx -- ){
            for(int bs = 0 ; bs <= 1 ; bs++){
                for(int cap = 1 ; cap <= k ; cap++){
                    int buy =0 , sell =0 ;
                    if(bs == 1){
                        buy = max(-prices[idx] + dp[idx+1][0][cap] , 0 + dp[idx+1][1][cap]);
                    }
                    else{
                        sell = max(prices[idx] + dp[idx+1][1][cap-1] , 0 + dp[idx+1][0][cap]);
                    }
                    dp[idx][bs][cap] =  max(buy,sell) ;
                }
            }
        }
        return dp[0][1][k] ;
        //return rec(0,1,2,prices , dp) ;
    }
};