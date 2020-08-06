/*
This is the iterative solution. This problem can be better solved recursively.
*/


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
        
        if(head == NULL)return NULL;
        Node* curr = head;
        stack<Node*> s;
        s.push(curr);
        bool flag = false;
        Node* prev = NULL; // This came in later after I edited the code to save the previous curr pointer. We need to attach.
        while(!s.empty())
        {
            auto node = s.top();
            
            s.pop();
            
            
            // This block is for attaching the curr list to remaining list.
            if(flag) 
            {
              curr = prev;
              curr->next = node;
              if(curr->next) // Keep these checks everywhere for next pointer
              curr->next->prev = curr;
              curr = curr->next;
            }

            while(curr)
            {
                prev = curr;
                if(curr->child)
                {
                    Node* temp = curr->next;
                    s.push(temp); // Stack helps to procrastinate and save it till for later. Also, what goes later will come out first.
                    flag = true;
                    
                    curr->next = curr->child;
                    curr->child = NULL; // Don't forget this.
                    curr->next->prev = curr; 
                }
                curr = curr->next;
            }
        }             
        
        return head;
    }
       
};
