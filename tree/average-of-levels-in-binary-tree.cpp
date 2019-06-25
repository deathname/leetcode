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
    
    void inOrder(TreeNode *root, map<int, pair<long int, int> >& mp, int level){
        if(!root){
            return;
        }
        
        if(mp.find(level) == mp.end()){
            mp[level] = make_pair(root->val, 1);
        }else{
            pair<long int, int > val = mp[level];
            mp[level] = make_pair((val.first + root->val),(val.second+1));
        }
        inOrder(root->left, mp, level+1);
        inOrder(root->right, mp, level+1);
    }
    
    
    vector<double> averageOfLevels(TreeNode* root) {
        map<int, pair<long int,int> > mp;
        inOrder(root, mp, 0);
        
        vector<double > ans;
        
        for(auto x: mp){
            double val = (x.second.first*1.0)/(x.second.second);
            ans.push_back(val);
        }
        return ans;
        
    }
};