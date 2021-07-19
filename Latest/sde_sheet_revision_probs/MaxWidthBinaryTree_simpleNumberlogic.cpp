/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        long long int res = 0;
        queue<pair<TreeNode*, long long int>> q;
        q.push({root, 0});
        int q_size = q.size();
        const long long int mod = INT_MAX + 1;
        int count = 0;
        while(!q.empty())
        {
            int curr = q.size();
            long long int left = INT_MAX;
            long long int right = INT_MIN;
            int offset = q.front().second;
            while(curr--)
            {
                auto node = q.front();
                q.pop();
                
                left = min(left, node.second);
                right = max(right, node.second);
                
                TreeNode* temp = node.first;
                int val = node.second;
                val -= offset;
                cout << val << endl;
                if(temp->left)
                {
                    q.push({temp->left, 2 * val + 1});
                }
                if(temp->right)
                {
                    q.push({temp->right, 2 * val + 2});
                }
            }
            res = max(res, abs(right - left));
        }
        return res + 1;
    }
};

// At each level, get the min and max x coordinate
