class Solution {
public:
    int countSubstrings(string s) {
       stack<string>st ;
        string ans ="" ;
        int ln = ans.size() ;
        for(int i = 0 ; i < s.size() ; i++){
            int l = i , r = i ;
            while( l>= 0 and r <s.size() and s[l] == s[r]){
                ans = s.substr(l ,r-l+1) ;
                st.push(ans) ;
                l-=1;
                r++ ;
            }
            l =i ,r = i+1 ;
            while( l>= 0 and r <s.size() and s[l] == s[r]){
                    ans = s.substr(l ,r-l+1) ;
                    st.push(ans) ;
                l-=1;
                r++ ;
            }
        }
        return st.size() ;
    }
};