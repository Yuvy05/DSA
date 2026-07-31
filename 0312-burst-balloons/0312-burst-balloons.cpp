class Solution {
public:
    int rec(int i , int j , vector<int>&a , vector<vector<int>>&dp){
        // base case 
        if(i>j)return 0;
        if(dp[i][j] != -1) return dp[i][j] ;
        int mx = INT_MIN ;
        for(int idx = i ; idx <= j ; idx++){
           int cost= a[i-1]*a[idx]*a[j+1] + rec(i,idx-1,a,dp) + rec(idx+1 , j ,a,dp) ;
           mx = max(cost , mx) ;
        }
        return dp[i][j]=mx ;
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1) ;
        nums.push_back(1) ;
        vector<vector<int>>dp(nums.size() + 2 , vector<int>(nums.size() +2,-1)) ;
        return rec(1,nums.size()-2,nums,dp) ;
    }
};