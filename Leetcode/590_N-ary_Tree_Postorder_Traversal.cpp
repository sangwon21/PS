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
    vector<int> ans;
    vector<int> postorder(Node* root) {
        if(root != nullptr)
        {
            for(auto t: root->children)
            {
                postorder(t);
            }
            ans.push_back(root->val);
        }
        return ans;
    }
};