/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        
        // 1->2->3->4 reverse k = 2    2->1 
        
        ListNode* newHead = NULL; // To get the new head that we get from reversing the first list. newHead is 2. One time use variable. I thought of this  earlier also.
       
        
        ListNode* prevHead = NULL; // We need to keep track of prevHead since it becomes the new tail!!!!!!
        
        ListNode* tail = NULL; // In first iteration, we don't have a tail but later we have. tail->next = prev attaches the lists.
        
        int length = 0;
        while(curr)
        {
            curr = curr->next;
            length++;
        }
        curr = head;
        int swaps = length/k;
    
        while(swaps--)
        {
             // 1 -> 2 -> 3, curr is 1. We need for joining.
            int t = k;
            prevHead = curr;
            
            while(curr && t--)
            {    next = curr->next;

                curr->next = prev;
                prev = curr;
                curr = next;
             }
            if(!newHead)
                newHead = prev;
            
            if(tail)
                tail->next = prev; // Attach the lists 
            
            if(swaps == 0) // Another condition required to get out of the loop. Also, we need to join rest of the part before exiting. 
            {
                prevHead->next = curr; // Curr is at the next list's head. PrevHead is out previous curr which is now the tail. Tail is still previous curr.
                break;
            }
            
            tail = prevHead;
        }
        prev = NULL;
        
        return newHead; 
        
    }
};
