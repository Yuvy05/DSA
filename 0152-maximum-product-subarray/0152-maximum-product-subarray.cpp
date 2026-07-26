class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ps = 1 , ss = 1 , mx = INT_MIN ;
        for(int i = 0 ; i < nums.size() ; i++){
            if(ps == 0) ps = 1 ;
            if(ss == 0) ss = 1 ;
            ps *= nums[i] ;
            ss *= nums[nums.size() - i - 1] ;
            mx = max({ps ,ss , mx}) ;
        }
        return mx ;
    }
};