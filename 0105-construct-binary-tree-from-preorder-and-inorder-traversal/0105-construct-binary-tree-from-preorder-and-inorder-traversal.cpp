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
    TreeNode* dfs(vector<int>& preorder,int ps , int preend ,vector<int>& inorder , int instart , int inend , map<int,int>&mp){
        if(instart > inend or ps  > preend) return NULL ;

        TreeNode* root = new TreeNode(preorder[ps]) ;
        int rootIdx = mp[root -> val] ;
        int rootLeftLen = rootIdx - instart ;

        root -> left = dfs(preorder , ps + 1 , ps + rootLeftLen , 
        inorder , instart , rootIdx - 1 , mp) ;

        root -> right = dfs(preorder , ps + rootLeftLen + 1, preend , 
        inorder , rootIdx+1, inend , mp) ;

        return root ;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>mp ;
        for(int i = 0 ; i < inorder.size() ; i++){
            mp[inorder[i]]=i ;
        }
        return dfs(preorder , 0 , preorder.size()-1 , inorder, 0 , inorder.size()-1,mp) ;
    }
};