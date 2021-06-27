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
    Node* flatten(Node* head) {
        
        Node* curr = head;
        
        stack<Node*> s;
        while(curr)
        {
            if(curr->child)
            {
                
                if(curr->next)
                s.push(curr->next);
                curr->next = curr->child; 
                curr->next->prev = curr; // Connect to prev pointer.
                curr->child = NULL;
            }
            if(curr->next == NULL)
            {   
                if(s.empty())break;
                
                Node* temp_next = s.top();
                s.pop();
                curr->next = temp_next;
                if(curr->next)
                {
                    curr->next->prev = curr; // Connect the prev of the stack wala next to current list.
                }
            }
            
            curr = curr->next;
        }
        return head;
    }
};
