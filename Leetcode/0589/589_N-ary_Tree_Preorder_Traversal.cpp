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
    vector<int> preorder(Node* root) {
        if(root != nullptr)
        {
            ans.push_back(root->val);
            
            for(const auto node : root->children)
            {
                preorder(node);    
            }
        }
        return ans;
    }
};