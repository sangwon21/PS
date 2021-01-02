/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <queue>

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        using namespace std;
        
        queue<pair<TreeNode*, int>> q;
        vector<double> averages;
        vector<double> nums;
        q.push(make_pair(root, 1));
        int prev = 1;
        
        while(!q.empty())
        {
            TreeNode* current = q.front().first;
            int depth = q.front().second;
            q.pop();
            if(prev != depth)
            {
                double sum = 0;
                for(auto num: nums)
                {
                    sum += num;
                }
                averages.push_back(sum / nums.size());
                nums.clear();
                prev = depth;
            }
            nums.push_back(current->val);
            
            if(current->left != nullptr)
            {
                q.push(make_pair(current->left, depth + 1));
            }
            if(current->right != nullptr)
            {
                q.push(make_pair(current->right, depth + 1));
            }
        }
        
        double sum = 0;
        for(auto num: nums)
        {
            sum += num;
        }
        averages.push_back(sum / nums.size());
        
        return averages;
    }
};