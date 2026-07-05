class Solution {
public:
    vector<int> productExceptSelf(vector<int>& n) {
        vector<int> res(n.size(),1);
        int prefix = 1 ;
        for(int i = 1 ; i < n.size() ; i++){
            res[i] = prefix* n[i-1] ;
            prefix *= n[i-1] ;
        }
        int postfix = 1 ;
        for(int i = n.size()-2 ; i >= 0 ; i--){
            res[i] *= postfix* n[i+1] ;
            postfix *= n[i+1] ;
        }
        return res ;
    }
};