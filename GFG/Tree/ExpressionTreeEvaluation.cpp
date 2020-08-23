/*
From the tree, it can be observed that only 
a postorder traversal of the tree is required.
*/

int evalTree(node* root) {
    if(root == NULL)
    {
        return 0;
    }
    int left = evalTree(root->left);
    int right = evalTree(root->right);
    
    if(root->data == "+" || root->data == "-" || root->data == "*" || root->data == "/")
    {
        if(root->data == "+")return left + right;
        else if(root->data == "-")return left - right;
        else if(root->data == "*")return left * right;
        else if(root->data == "/")return left / right;
    }
    if(left == 0)return stoi(root->data); // This is sort of base case only. I could have alternatively returend the value when reached a leaf node.
    if(right == 0)return stoi(root->data);
    
}
