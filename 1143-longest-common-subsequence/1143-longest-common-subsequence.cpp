class Solution {
public:
    int rec(int i , int j , string &s1 , string &s2,vector<vector<int>>&dp){ 
        if(i == 0 or j == 0) return 0 ;
        if(dp[i][j] != -1) return dp[i][j] ;
        // match
        if(s1[i-1] == s2[j-1])
            return dp[i][j] = 1 + rec(i-1 , j-1 , s1 , s2,dp) ;
        // not match
        return dp[i][j] =  0 + max(rec(i-1,j,s1,s2,dp) , rec(i,j-1,s1,s2,dp)) ;
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>dp(text1.size()+1 , vector<int>(text2.size()+1,0)) ;
        //return rec(text1.size() , text2.size() , text1 , text2,dp) ;
        for(int i = 1 ; i <= text1.size() ; i++){
            dp[i][0] = 0 ;
        }
        for(int i = 1 ; i <= text2.size() ; i++){
            dp[0][i] = 0 ;
        }
        string s1 = text1 , s2 = text2 ;
        for(int i = 1 ; i <= text1.size() ; i++){
            for(int j = 1 ; j <= text2.size() ; j++){
                // if(dp[i][j] != -1) return dp[i][j] ;
                // match
                if(s1[i-1] == s2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1] ;
                // not match
                else dp[i][j] =  0 + max(dp[i-1][j],dp[i][j-1]) ;
            }
        }
        return dp[text1.size()][text2.size()] ;
    }
};