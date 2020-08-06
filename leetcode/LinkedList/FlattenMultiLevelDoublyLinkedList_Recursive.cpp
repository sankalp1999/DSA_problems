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
                Node* temp = curr->next;
                curr->next = flatten(curr->child);
                curr->child = NULL;
                curr->next->prev = curr;
                while(curr->next)curr = curr->next;
                curr->next = temp;
                if(curr->next)
                curr->next->prev = curr;
            }
            curr = curr->next;
        }
        
        return head;
       
    }
};
