/*
Explanation:
If 0 children, then we simply delete the node.
If 1 children, then we connect it to its' grandparent e.g if(root->left == NULL) then root = root->right;
                                                          if(root->right == NULL) then root = root->left;
If 2 children present, we delete this node. But, then the arrangement of the tree will get messed up.
So, how to retain the property of the BST?
-> We find the next larger element or the smallest element in the right sub-tree. This will ensure that whatever is in the left subtree
   will still be smaller than our new root. All the nodes in the right subtree will still be larger than our current node since it was the 
   smallest node earlier.
   
 -> A case arises when this smallest node in the right subtree might have a child. (It can't have 2 children because 1. It won't be the smallest then because it is going to have a node as a left child.
 2. It can have one child on right only.)
 So, we run a delete node in the right subtree.
 
 */
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
    
    TreeNode* FindMin(TreeNode* root)
    {
        while(root->left) root = root->left;
        return root;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        /* First, search for the element to be deleted */
        
        if(root == NULL)
        {
            return root;
        }
        else if(key < root->val)
        {
            root->left = deleteNode(root->left, key);
        }
        else if(key > root->val)
        {
            root->right = deleteNode(root->right, key);
        }

        else 
        {
            // Time to delete the BST node
           
            if(root->left == NULL && root->right == NULL)
            {
                return NULL;
            }
            
            //One child case
            else if(root->left == NULL)
            {
                // Delete current and make link to right child
                root = root->right;
            }
            else if(root->right == NULL)
            {
                root = root->left;
            }
            else if(root->right && root->left)// Both children are present
            {
                TreeNode* temp = FindMin(root->right); // Find the min element in the right subtree.
                int val = temp->val;
                root->right = deleteNode(root->right, temp->val);
                root->val = val;
            }
        }
        return root;
    }
};
