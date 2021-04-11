
// Since, we need to return multiple things, make a struct.
struct info{
    int min;
    int max;
    bool isBst;
    int size;
};


// We travel in a bottom up manner. i.e postorder so that 
// we can get the data from the leaf nodes 

// Leaf nodes are BST.

// A non-leaf node is BST if it's both subtrees are BST
// and left.max < curr->val > right.min

// Since, left and right are bst, we can just 
// add the curr node and extend the bst since it 
// satisfies the properties.

// size will be left + right + 1

// Now if one of the subtrees is not BST, we can 
// simply pass a struct with the best answer we have till now.


info solve(Node* root)
{
	if(root == NULL)
	{
	    return {INT_MAX, INT_MIN, true, 0};
	}
	if(root->left == NULL && root->right == NULL)
	{
	    return {root->data, root->data, true, 1};
	}
	info left = solve(root->left);
	info right = solve(root->right);
	info curr;
	curr.size = left.size + right.size + 1;
    // Main condtion
	if(left.isBst && right.isBst && left.max < root->data && right.min > root->data)
	{
	     curr.min = min({left.min,right.min,root->data});
	     curr.max = max({left.max,right.max,root->data});
	     curr.isBst = true;
	    return curr;
	}
	else
	{
	    curr.isBst = false;
	    curr.size = max(left.size, right.size);
	    return curr;
	}
 
	
	
}

int largestBst(Node *root)
{   
    // int res = 0 ;
    info res = solve(root);
	return res.size;
}