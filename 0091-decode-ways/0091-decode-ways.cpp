class Solution {
public:
    int rec(int idx , vector<int>&dp , string &s){
        if(idx == s.size()) return 1 ;
        if(s[idx] == '0') return 0 ;


        if(dp[idx] != -1)return dp[idx] ;
        //take one digit
        int take = 0 ;
        if(s[idx] != '0')
            take += rec(idx+1 , dp ,s) ;

        // take 2 digits
        if(idx+1 < s.size() and s[idx] != '0' and(s[idx] == '1' or (s[idx] <= '2' and s[idx+1] < '7')))
            take += rec(idx+2,dp,s) ;
        return dp[idx] = take;
    }
    int numDecodings(string s) {
        int n = s.size() ;
        vector<int>dp(n,-1) ;
        return rec(0,dp,s) ;
    }
};