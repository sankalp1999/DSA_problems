/*
Check for limits as well as
duplication
*/
  bool helper(Node* root, int min_val, int max_val)
  {
      if(root == NULL)
          return true;

      bool left = helper(root->left,min_val, root->data) ;

      bool right = helper(root->right,root->data,max_val);

      // equal to is for checking duplication also
      if(root->data <= min_val || root->data >= max_val) 
      {
          return false;
      }

      return left && right;   
  }
bool checkBST(Node* root) {
int min_val = -1e5;
int max_val = 1e5;
	return helper(root, min_val, max_val);
}
