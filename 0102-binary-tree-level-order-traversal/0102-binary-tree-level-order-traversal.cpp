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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL) return {} ;
        queue<TreeNode*>q ;
        q.push(root) ;
        vector<vector<int>>ans ;
        while(q.size()){
            vector<int> v ;
            int sz = q.size() ;
            for(int i = 0 ; i < sz ; i++){
                TreeNode* t = q.front() ; q.pop() ;
                v.push_back(t -> val ) ;
                if(t -> left != NULL) q.push(t->left) ;
                if(t -> right != NULL) q.push(t->right) ;
            }
            ans.push_back(v) ;
        }
        return ans ;
    }
};