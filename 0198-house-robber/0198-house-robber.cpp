class Solution {
public:

    // recursive or memoization
    int f(int idx , vector<int>&nums , vector<int>&dp){
        if(idx == 0) return nums[idx] ;
        if(idx < 0) return 0 ;
        //pick
        if(dp[idx] != -1) return dp[idx] ;
        int pick = nums[idx] + f(idx-2,nums,dp) ;
        //not pick
        int notpick = 0 + f(idx-1,nums,dp) ;

        return dp[idx] =  max(pick,notpick) ;
    }
    int rob(vector<int>& nums) {
        int n = nums.size() ;
        vector<int>dp(nums.size(),-1) ;
        dp[0] = nums[0] ;
        //dp[1] = cost[1] ;
        for(int i = 1 ; i < n ; i++){
            int take = nums[i] ; if (i>1) take +=  dp[i-2]  ;
            int notake = 0 + dp[i-1] ;
            dp[i] = max(take,notake) ;
        }
        return dp[n-1] ;
        //return f(n-1 , nums,dp) ;
    }
};