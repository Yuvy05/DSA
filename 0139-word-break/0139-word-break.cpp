class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool>dp(s.size()+1 , false ) ;
        dp[s.size()] = true ;
        for(int i = s.size() - 1 ;i >= 0; i --){
            for(auto w : wordDict){
                if(s.substr(i,w.length()) == w){
                    dp[i] = dp[i+w.length()] ;
                }
            
                if(dp[i] == true) break ;// dont check for more words in dictionary
            }
        }
        return dp[0] ;
    }
};