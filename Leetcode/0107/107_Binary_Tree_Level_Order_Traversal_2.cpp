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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr)
        {
            return ans;
        }
        
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 0));
        int prev = 0;
        vector<int> v;
        
        while(!q.empty())
        {
            TreeNode* cur = q.front().first;
            int depth = q.front().second;   
            q.pop();
            
            if(depth != prev)
            {
                ans.push_back(v);
                v.clear();
                prev = depth;
                
            }
            v.push_back(cur->val);
            
            if(cur->left != nullptr)
            {
                q.push(make_pair(cur->left, depth + 1));
            }
            if(cur->right != nullptr)
            {
                q.push(make_pair(cur->right, depth + 1));
            }
        }
        
        ans.push_back(v);
        v.clear();
                
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};