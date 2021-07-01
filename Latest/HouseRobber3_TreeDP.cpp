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
    // House Robber 3
    // Two solutions
    // O(n) soln which uses pairs
    
    // Pair stores [WithRoot, WithoutRoot]
    pair<int,int> dfs(TreeNode* root)
    {
        if(root == NULL)
        {
            return {0,0};
        }
        
        auto left  = dfs(root->left);
        auto right = dfs(root->right);
        
        // We include current root and sum of (without root) values from left and right subtrees.
        // Notice, we don't have choice of getting next root but we can get both the values
        // from left.second and right.second
        int withRoot = root->val + left.second + right.second;
        int withoutRoot = max(left.first,left.second) + max(right.first, right.second);
        return {withRoot, withoutRoot};
    }
    
    unordered_map<TreeNode* ,int> mapper;
    int solve(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        if(mapper.find(root)!=mapper.end())return mapper[root];
        
        
        int sum = root->val; // Current and next to next  
        if(root->left)
        {
            sum += solve(root->left->left) + solve(root->left->right);
        }
        if(root->right)
        {
            sum += solve(root->right->left) + solve(root->right->right);
        }
        
        // We recursively get the sum of the next level without current root value
        int next = solve(root->left) + solve(root->right);
        
        return mapper[root] = max(sum, next);
    }
    
    
    
    
    int rob(TreeNode* root) {
        // auto pa = dfs(root);
        return solve(root);
        // return max(pa.first, pa.second);
    }
};
