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
#include <queue>
class Solution {
public:
    
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if(root == nullptr)
        {
            return ans;
        }
        queue<pair<Node*, int>> q;
        q.push(make_pair(root, 1));
        vector<int> v;
        int prev = 1;
        while(!q.empty())
        {
            Node* node = q.front().first;
            int num = q.front().second;
            q.pop();
            
            if(prev != num)
            {
                ans.push_back(v);
                v.clear();
                prev = num;
            }
            v.push_back(node->val);
            
            for(auto child: node->children)
            {
                if(child == nullptr)
                {
                    continue;
                }
                q.push(make_pair(child, num + 1));
            }
        }
        ans.push_back(v);
        
        return ans;
    }
};