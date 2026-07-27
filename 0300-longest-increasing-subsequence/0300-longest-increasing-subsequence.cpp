class Solution {
public:
    int rec(vector<int>&nums , int idx , int prev_idx , vector<vector<int>>&dp){
        //base case 
        if(idx == nums.size()) return 0 ;
        if(dp[idx][prev_idx+1] != -1) return dp[idx][prev_idx+1] ;
        // pick
        int pick =  0 , notpick = 0 ;
        if(prev_idx == -1 or nums[prev_idx] < nums[idx])
            pick = 1 + rec(nums , idx + 1 , idx,dp) ;
        notpick = 0 + rec(nums , idx+1 , prev_idx ,dp ) ;
        return dp[idx][prev_idx+1] = max(pick,notpick) ;
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>>dp(nums.size() , vector<int>(nums.size() + 1 , -1)) ;
        return rec(nums , 0 , -1 , dp ) ;
    }
};