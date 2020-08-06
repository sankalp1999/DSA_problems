/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
class Solution {
public:
    Node* flatten(Node* root) {
          if(root == NULL)
        return NULL;
        
    Node* curr = root;
    stack<Node*> s;
    // We only push inside the stack if it has a child, otherwise no need.
    while(curr)
    {
        if(curr->child != NULL)
        {
            if(curr->next != NULL)
            {
                s.push(curr->next);
            }
            curr->next = curr-> child;
            curr->next->prev = curr;
            curr->child = NULL;
            
        }
        else if(curr->next == NULL && !s.empty()) // No need of prev pointer
        {
            Node* rest = s.top();
            s.pop();
            curr->next = rest; // If curr->next is empty, time to make connection
            curr->next->prev = curr;
        }
        curr = curr->next;
    }
    return root;
        
    }
};
