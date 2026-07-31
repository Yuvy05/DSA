class Solution {
public:
    int rec(int i , int j , string &s1 , string &s2 ,vector<vector<int>>&dp){
        // base case 
        if(i<0) return j+1 ;
        if(j<0) return i+1 ;
        if(dp[i][j] !=-1) return dp[i][j] ;
        if(s1[i] == s2[j]){
            return dp[i][j]=rec(i-1,j-1,s1,s2,dp) ;
        }
        else{
            // insert , delete,replace
            return dp[i][j]=min({1+ rec(i,j-1,s1,s2,dp) , 1+rec(i-1,j,s1,s2,dp) , 1+rec(i-1,j-1,s1,s2,dp)}) ;
        }
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>>dp(word1.size() , vector<int>(word2.size() , -1)) ;
        return rec(word1.size()-1,word2.size()-1 , word1,word2,dp) ;
    }
};