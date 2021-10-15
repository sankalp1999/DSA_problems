class Solution
{
    public:
    //Function to return a list of integers denoting the node 
    //values of both the BST in a sorted order.
    vector<int> merge(Node *root1, Node *root2)
    {
       //Your code here
        stack<Node*> s1;
        stack<Node*> s2;
        Node* curr1 = root1;
        Node* curr2 = root2;
        vector<int> res;
        while( (!s1.empty() or curr1) and (!s2.empty() or curr2) )
        {   
            while(curr1)
            {
                s1.push(curr1);
                curr1 = curr1->left;
            }
            while(curr2)
            {
                s2.push(curr2);
                curr2 = curr2->left;
            }
            // Maybe just compare the tops. Whichever is smaller, move that forward
            // in iteration
            
            int val1 = s1.top()->data;
            int val2 = s2.top()->data;
            if(val1 == val2)
            {
                res.push_back(s1.top()->data);
                res.push_back(s2.top()->data);
                
                curr1 = s1.top();
                s1.pop();
                curr2 = s2.top();
                s2.pop();
                
                curr1 = curr1->right;
                curr2 = curr2->right;
            }
            else if(s1.top()->data > s2.top()->data)
            {
                res.push_back(val2);
                curr2 = s2.top();
                s2.pop();
                curr2 = curr2->right;
            }
            else
            {
                res.push_back(val1);
                curr1 = s1.top();
                s1.pop();
                curr1 = curr1->right;
            }
        }
        
        
        while(!s1.empty() or curr1 != NULL)
        {
             while(curr1)
            {
                s1.push(curr1);
                curr1 = curr1->left;
            }
         
            
            curr1 = s1.top();
            res.push_back(curr1->data);
            s1.pop();
            curr1 = curr1->right;
        }
        while(!s2.empty() or curr2)
        {
            while(curr2)
            {
                s2.push(curr2);
                curr2 = curr2->left;
            }
       
            curr2 = s2.top();
            res.push_back(curr2->data);
            s2.pop();
            curr2 = curr2->right;
        }
        
        
        return res;
    
    }
};
