/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    void n_ary_pre(Node *root, vector<int > &a){
        if(!root){
            return;
        }
        a.push_back(root->val);
        vector<Node* > child = root->children;
        for(int i=0;i<child.size();i++){
            n_ary_pre(child[i], a);   
        }
    }
    
    vector<int> preorder(Node* root) {
        vector<int > ans;
        n_ary_pre(root,ans);
        return ans;
    }
};