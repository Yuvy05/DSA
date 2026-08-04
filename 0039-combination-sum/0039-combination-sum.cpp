class Solution {
public:
    void rec(int idx , vector<int> ans , vector<vector<int>>&res  , vector<int>& nums, int target){
        // base case 
        if(idx == nums.size()){
            return ;
        }
        if(target == 0){
            res.push_back(ans) ;
            return ;
        }
        // pick 
        if(target >= nums[idx]){
            ans.push_back(nums[idx]) ;
            rec(idx , ans , res , nums ,target-nums[idx]) ;
            ans.pop_back() ;
        }

        // not pick
        rec(idx+1 , ans ,res , nums ,target) ;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> ans ;
        vector<vector<int>>res ;
        rec(0,ans, res , candidates , target) ;
        return res ;
    }
};