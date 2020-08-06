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
        Node* temp = NULL;
        while(curr)
        {
            if(curr->child)
            {
                Node* temp = curr->next; // Store the next link in stack
                
                curr->next = flatten(curr->child); // This will connect child list
                
                curr->child = NULL; // Rectify the connections properly
                curr->next->prev = curr;
                
                while(curr->next)curr = curr->next; // Go to the end of this list
                curr->next = temp; // And make the connection
                
                if(curr->next) 
                curr->next->prev = curr; // Make previous connection
            }
            curr = curr->next; // Continue for next level.
        }
        
        return head;
       
    }
};
