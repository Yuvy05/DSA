class Solution {
public:
    bool rec(int i , int j , string&s , string &p){
        //base case 
        if(i<0 and j < 0) return true ;
        if(i>=0 and j<0) return false ;
        if(i<0 and j>=0){
            if((j+1)%2 == 0){ // even number of characters only
                for(int x = j ; x>= 0 ; x-=2){
                    if(p[x] != '*') return false ;
                }
                return true ;
            }
            return false ;
        }
        //letters are same or they have ?
        if(s[i] == p[j] or p[j] == '.'){
            return rec(i-1,j-1,s,p) ;
        }
        else if(p[j] == '*'){
            //take
            bool take = false ;
            if(j > 0 and (s[i] == p[j-1] or p[j-1] == '.')){
                take = rec(i-1 , j ,s,p) ; 
            }
            bool nottake = false ;
            nottake = rec(i,j-2,s,p) ;
            return take or nottake ;
            // return rec(i,j-2,s,p) or rec(i-1,j,s,p) ;
        }
        return false ;
    }
    bool isMatch(string s, string p) {
        return rec(s.size()-1,p.size()-1,s,p) ;
    }
};