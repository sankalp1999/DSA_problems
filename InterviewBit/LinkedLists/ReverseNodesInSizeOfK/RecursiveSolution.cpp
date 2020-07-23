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
    ListNode* reverse(ListNode* head, int k, int& swaps)
    {
        if(swaps==0)return head;
        swaps--;
        ListNode* current = head;
        ListNode* next = NULL;
        ListNode* prev = NULL;
        int count = 0;
        
        //Regular Reverse k nodes
        while(current && count < k)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
            count++;
        }
        
        if(next!=NULL)
            head->next = reverse(next, k, swaps); // We pass curr or next (same) since that is our new node.
        return prev; // new head will be prev/
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        int len = 0;
        ListNode* curr = head;
        while(curr)
        {
            curr = curr->next;
            len++;
        }
        int swaps = len/k;
        return reverse(head, k, swaps);
    }
};
