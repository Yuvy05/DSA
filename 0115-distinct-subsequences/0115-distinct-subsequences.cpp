class Solution {
public:
    int rec(int i , int j , string &s , string &t,vector<vector<int>>&dp){
        // base case
        if(j<0) return 1 ;
        if(i<0) return 0 ;
        if(dp[i][j] != -1) return dp[i][j] ;

        if(s[i] == t[j]){
           return dp[i][j]=rec(i-1,j-1,s,t,dp) + rec(i-1,j,s,t,dp) ;
        }
        else return dp[i][j] =  rec(i-1,j,s,t,dp) ;
    }
    int numDistinct(string s, string t) {
        vector<vector<int>>dp(s.size() +1, vector<int>(t.size() , -1)) ;
        return rec(s.size() - 1 , t.size()-1,s,t , dp) ;
    }
};