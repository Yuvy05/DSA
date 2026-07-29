class Solution {
public:
    int rec(int idx , vector<int>&nums , int target){
        // base case 
        if(idx == nums.size() and target == 0) return 1 ;
        if(idx == nums.size()) return 0 ;
        //pos
        int pos = rec(idx+1 , nums , target-nums[idx]) ;
        //neg
        int neg = rec(idx+1 , nums , target +nums[idx]) ;
        return pos+neg ;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return rec(0,nums,target );
    }
};