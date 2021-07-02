// We reverse the list from the middle. 
// This enables us to traverse from middle and then alternate the nodes.
// Also, don't join the lists after reversing. Keep them 
// separate. This helps in the joining part to exit the loop.
class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prevBegin = head;
        int count = 0;
        while(fast and fast->next)
        {
            count++;
            prevBegin = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* curr = slow;
        ListNode* next;
        ListNode* prev = NULL;
        while(curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        // prevBegin->next = prev;
        prevBegin = prev;
        curr = head;
        while(curr)
        {
            // cout << curr->val << " " << prevBegin->val << endl;
            next = curr->next;
            curr->next = prevBegin;
            curr = next;
            
            if(curr==prevBegin)break;
            ListNode* temp = prevBegin->next;
            prevBegin->next = curr;
            prevBegin = temp;
            
        }
        // Slow is the middle pointer.
        
    }
};
