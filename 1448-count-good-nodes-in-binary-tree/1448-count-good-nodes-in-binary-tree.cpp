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
    int ct = 0 ;
    void dfs(TreeNode*root , int mx){
        if(root == NULL) return  ;
        if(root -> val >= mx){
            ct++ ;
        }
        dfs(root -> left , max(mx , root -> val)) ;
        dfs(root -> right, max(mx , root -> val)) ;
        
    }
    int goodNodes(TreeNode* root) {
        dfs(root , root ->val) ;
        return ct ;
    }
};