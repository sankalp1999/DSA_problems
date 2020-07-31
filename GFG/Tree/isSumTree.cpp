int helper(Node* root, int& flag)
{
    if(root == NULL)return 0;
    int left = helper(root->left, flag);
    int right = helper(root->right, flag);
    
    if(left + right != root->data && (root->left || root->right))flag = 1;
    return left + right + root->data;
}

// Should return true if tree is Sum Tree, else false
bool isSumTree(Node* root)
{   
     int flag = 0;
     helper(root, flag);
     if(flag == 0)return true;
     else return false;
}
