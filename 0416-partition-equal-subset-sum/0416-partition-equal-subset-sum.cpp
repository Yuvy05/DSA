class Solution {
public:
    bool subset_sum(int idx , vector<int>&nums , int target , vector<vector<int>>&dp ){
        //base case 
        if(target == 0) return true ;
        if(idx == nums.size()) return false ;
        if(dp[idx][target] != -1) return dp[idx][target] ;

        //pick
        bool pick = false , notpick = false ;
        if(target >= nums[idx]){
            pick = pick or subset_sum(idx+1 , nums , target - nums[idx],dp) ;
        }
        notpick = notpick or subset_sum(idx+1 , nums , target,dp) ;
        return dp[idx][target] =  pick or notpick ;
    }
    bool canPartition(vector<int>& nums) {
        int s = 0;
        for(int i = 0 ; i< nums.size() ; i++){
            s+= nums[i] ;
        }
        if(s%2 == 1)return false ;
        vector<vector<int>>dp(nums.size() , vector<int>(s/2+1 , -1)) ;
        bool target = subset_sum(0 , nums , s/2,dp) ;
        return target ;
    }
};