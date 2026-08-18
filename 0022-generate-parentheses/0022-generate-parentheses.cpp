class Solution {
public:
    void rec(int n , string s , int open , int close,vector<string> &ans){
        // base case 
        if(open == n/2 and close == n/2){
            ans.push_back(s) ;
            return ;
        }
        if(open < n/2){
            rec(n,s+"(",open+1,close,ans) ;
        }
        if(close < open){
            rec(n,s+")",open,close+1,ans) ;
        }

    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans ;
        rec(n*2,"",0,0,ans);
        return ans ;
    }
};