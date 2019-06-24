/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* ans;
    TreeNode* increasingBST(TreeNode* root) {
        ans = new TreeNode(0);
        TreeNode *t = ans;
        solve(root);
        return t->right;
    }
    
    void solve(TreeNode* root){
        if(!root){
            return; 
        }
        solve(root->left);
        TreeNode* temp = new TreeNode(root->val);
        ans->right = temp;
        ans = temp;
        solve(root->right);
    }
};