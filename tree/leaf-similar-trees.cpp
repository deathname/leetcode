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
    void getLeaf(TreeNode *root, vector<int >& leaf){
        if(!root){
            return;
        }
        if(!root->left && !root->right){
            leaf.push_back(root->val);
            return;
        }
        getLeaf(root->left,leaf);
        getLeaf(root->right,leaf);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int > leaf1,leaf2;
        getLeaf(root1, leaf1);
        getLeaf(root2, leaf2);
        if(leaf1 == leaf2){
            return true;
        }else{
            return false;
        }
        
    }
};