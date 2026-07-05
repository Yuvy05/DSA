class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(!nums.size()) return 0 ;
        unordered_set<int>st(nums.begin() ,nums.end()) ;
        int mx = 1 ,ct_l ,ct_h;
        for(auto i : st){
            if(st.count(i-1) == 0){
                ct_l = i , ct_h = i ;
                while(st.count(ct_h+ 1)){
                    ct_h ++ ;
                    mx = max(mx , ct_h-ct_l +1) ;
                }
            }
        }
        return mx ;
    }
};