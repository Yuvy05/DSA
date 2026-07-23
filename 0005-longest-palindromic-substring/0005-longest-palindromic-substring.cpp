class Solution {
public:
    string longestPalindrome(string s) {
        string ans = "" ;
        int ln = ans.size() ;
        for(int i = 0 ; i < s.size() ; i++){
            int l = i , r = i ;
            while( l>= 0 and r <s.size() and s[l] == s[r]){
                if(ln < r-l+1){
                    ans = s.substr(l ,r-l+1) ;
                    ln = ans.size() ;
                }
                l-=1;
                r++ ;
            }
            l =i ,r = i+1 ;
            while( l>= 0 and r <s.size() and s[l] == s[r]){
                if(ln < r-l+1){
                    ans = s.substr(l ,r-l+1) ;
                    ln = ans.size() ;
                }
                l-=1;
                r++ ;
            }
        }
        return ans ;
    }
};