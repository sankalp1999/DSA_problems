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


/* Single Traversal solution. Here we do a reversed inorder traversal */

public:
    
    
    void solve(TreeNode* root,int& pre)
    {
        if(root == NULL)
        {
            return;
        }
        solve(root->right, pre);
        pre = root->val = root->val + pre;
        solve(root->left, pre);
        
    }
    
    
    TreeNode* bstToGst(TreeNode* root) {
     
        int pre = 0;
        TreeNode* temp = root;
        solve(root, pre);
        return temp;
    }
};


/* My first solution. Here, i am doing a similar thing by finding the sum first.
 And then subtracting it and then assigning the value */

 void inorder(TreeNode* root, int& sum)
    {
        if(root == NULL)
        {
            return;
        }

        inorder(root->left, sum);
        sum += root->val;
        inorder(root->right, sum);
    }
    
    void solve(TreeNode* root, int& sum)
    {
        if(root == NULL)
        {
            return;
        }
        solve(root->left, sum);
        sum -= root->val;
        root->val = sum + root->val;
        solve(root->right,sum);
        
    }
    
    TreeNode* bstToGst(TreeNode* root) {
        // inorder sum of a bst is a sorted array.
        // do a inorder traversal. Get the sum.
        int sum = 0;
        TreeNode* temp = root;
        TreeNode* dummy = root;
        inorder(root, sum);
        vector<int> res;
        solve(temp,sum);
        return dummy;
        
    }