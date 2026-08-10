class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)return false; 
        long long d = x ;
        long long rev = 0;
        while(x!=0){
            int one =x%10 ; 
            rev = rev*10 + one ;
            x/= 10 ;
        }
        return(rev == d) ;
    }
};