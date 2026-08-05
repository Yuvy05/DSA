class Solution {
public:
    void backtrack(vector<int>& nums,
                   vector<int>& current,
                   vector<int>& used,
                   vector<vector<int>>& ans) {

        // Base Case
        if (current.size() == nums.size()) {
            ans.push_back(current);
            return;
        }

        // Try every unused element
        for (int i = 0; i < nums.size(); i++) {

            // Skip if already used
            if (used[i])
                continue;

            // Choose
            current.push_back(nums[i]);
            used[i] = 1;

            // Explore
            backtrack(nums, current, used, ans);

            // Backtrack (Undo)
            current.pop_back();
            used[i] = 0;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> current;
        vector<int> used(nums.size(), 0);

        backtrack(nums, current, used, ans);

        return ans;
    }
};