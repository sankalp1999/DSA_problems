/*
Same logic for BST.
We do an inorder traversal. 
We pass a prev variable. Notice that we pass pointer via reference. 
The head of the list will be leftmost node in the tree. This will
get initialized only when we reach there. Also, we need the previous node 
for the connection.



void inorder1(Node* root, Node*& headList, Node*& prev)
{
    if(root == NULL)
        return ;
    inorder1(root->left, headList, prev);
    
    if(prev == NULL)// If previous is NULL, then we are head of linkedlist
    {
        headList = root;
        prev = headList;
    } 
    else 
    {
        root->left = prev; // Prev is passed from left to root and from root to right in some cases.
        prev->right = root;
        prev = root;
    }
     inorder1(root->right, headList, prev);
}


Node * bToDLL(Node *root)
{
    Node* headList = NULL;
    Node* prev = NULL;
    inorder1(root, headList, prev);
    return headList;
}
