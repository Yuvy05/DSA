/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool dfs(TreeNode *root , long long mx , long long mn){
        if(root == NULL) return true ;
        if(root -> val <= mn or root -> val >= mx) return false ;
        return dfs(root -> left , root -> val , mn) and dfs(root -> right , mx , root -> val) ;
    }
    bool isValidBST(TreeNode* root) {
        return dfs(root , LLONG_MAX , LLONG_MIN) ;
    }
};