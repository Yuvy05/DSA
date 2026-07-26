class Solution {
public:
    int rec(int idx , vector<int>&coins , int amount , vector<vector<int>>&dp){
        if (amount == 0) return 0 ; 
        if(idx == 0 ){
            if(amount%coins[idx] == 0)
                return amount/coins[0] ;
            return 1e9 ; 
        }
        if(dp[idx][amount] != -1) return dp[idx][amount] ;

        int take = INT_MAX , nottake = 0;
        if(coins[idx] <= amount){
            take = 1 + rec(idx , coins , amount - coins[idx] , dp) ;
        }

        //nottake
        nottake += 0 + rec(idx-1 , coins , amount , dp) ;
        return dp[idx][amount] = min(take,nottake) ;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(coins.size() ,vector<int>(amount+1,-1));
        int ans = rec(coins.size()-1 , coins , amount , dp) ;
        return ans == 1e9 ? -1 : ans ;
    }
};