class Solution {
public:
    void rec(int idx , vector<vector<int>> &res , vector<int> ans , vector<int>&nums){
        // base case 
        if(idx == nums.size()) {
            res.push_back(ans) ;
            return ;
        }
        // pick
        ans.push_back(nums[idx]) ;
        rec(idx+1 , res , ans, nums) ;
        ans.pop_back() ;

        //not pick
        rec(idx+1 , res , ans , nums) ;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res ;
        vector<int> ans ;
        rec(0,res , ans , nums) ;
        return res ; 
    }
};