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
    TreeNode* Succ(TreeNode* curr)
    {
        while(curr->left) curr = curr->left;
        return curr;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if(root == NULL)
            return NULL;
        if(key < root->val)
        {
            root->left = deleteNode(root->left, key);
        }
        else if(key > root->val)
        {
            root->right = deleteNode(root->right, key);
        }
        else
        {
            // Get ready to be deleted
            if(root->left == NULL) // Then only one child and no child case
            {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            else if(root->right == NULL) // Then only one child and no child case
            {
                TreeNode* temp = root->left; // Attach the left child to the parent
                delete root;
                return temp;
            }
            
            // 2 children case here.
            TreeNode* inorder = Succ(root->right);
            root->val = inorder->val;
            root->right = deleteNode(root->right, inorder->val);
        }
        return root;
    }
};
