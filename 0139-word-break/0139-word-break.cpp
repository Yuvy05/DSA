class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool>dp(s.size()+1 , false) ;
        dp[s.size()] = true ;
        int i = s.size() - 1 ;
        while(i>=0){
            for(auto j : wordDict){
                int start = i - (int)j.size() + 1;
                if(start >= 0 and s.substr(start,j.size()) == j){
                    dp[start] = dp[start] or dp[i+1] ;
                }
            }
            i-- ;
        }
        return dp[0] ;
    }
};