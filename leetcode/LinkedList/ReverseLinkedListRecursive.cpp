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
    
    void helper(ListNode* head, ListNode* &newHead)
    {
        if(head->next == NULL)
        {
            newHead = head;
            return;
        }
        helper(head->next, newHead);
        // Go to next node
        ListNode* temp = head->next; // 1 2 3 4 (5)-> 6 go to 6 and make reverse connection
                                // and erase the current node's next.
        temp->next = head;
        head->next = NULL;
        
    }
    
    
    ListNode* reverseList(ListNode* head) {
        
        if(head == NULL)return NULL;
        ListNode* newHead = NULL;
        helper(head, newHead);
        return newHead;
    }
};
