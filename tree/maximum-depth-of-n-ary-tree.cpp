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
    int getHeight(Node* root) {
        if(!root){
            return 0;
        }
        int ans = 0;
        vector<Node* > ch = root->children;
        for(int i=0;i<ch.size();i++){
            ans = max(ans, 1+getHeight(ch[i]));
        }
        return ans;
    }
    
    int maxDepth(Node* root){
        if(!root){
            return 0;
        }
        return 1+getHeight(root);
    }
    
};