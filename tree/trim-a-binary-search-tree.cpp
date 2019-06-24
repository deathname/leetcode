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
    TreeNode* insertBST(TreeNode* root, int val){
        if(!root){
            TreeNode *t = new TreeNode(val);
            return t;
        }
        
        if(root->val < val){
            root->right = insertBST(root->right,val);
        }
        else if(root->val > val){
            root->left = insertBST(root->left,val);
        }
        return root;
    }
    
    void search(TreeNode* root, int L,int R){
        if(!root){
            return;
        }   
        if(root->val >= L && root->val <= R){
            ans = insertBST(ans, root->val);
        }
        search(root->left, L, R);
        search(root->right, L, R);
    }
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        search(root, L, R);
        return ans;
    }
};