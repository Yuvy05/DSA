class Solution {
public:
    bool canJump(vector<int>& nums) {
        int mxreachidx = 0 ;
        for(int i = 0 ; i < nums.size();i++){
            // base case 
            // cant reach
            if(i>mxreachidx)return false ;

            mxreachidx = max(mxreachidx , i + nums[i]) ;

            // can reach
            if(mxreachidx >= nums.size()-1) return true ;
        }
        return false ;
    }
};