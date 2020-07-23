struct node *reverse (struct node *head, int k)
{ 
    node* curr = head;// Reverse
    node* prev = NULL;// Prev pointer and it becomes new head everytime except first time.
    node* next = NULL; //Store next pointer while reversing
    
    node* newHead = NULL; // Only for the first time, it stores the newHead.    
    
    // We need to keep track of the head and tail to attach later.
    node* tail = NULL;
    node* preHead = NULL; // Basically, store the head of the list that we are reversring.
    
    while(curr)
    {
        preHead = curr;
        prev = NULL;
        int t = k;
        while(curr && t--)
        {
            next = curr->next; 
            
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        // 1->2->3->4->5->6 
        // First Iteration
        //3 -> 2 -> 1 preHead = 3; tail = NULL; newHead = 3. tail becomes 1.
        // 3 - > 2 - > 1 We make prev NULL in next iteration
        // Or when loop ends, we can make prev NULL .
        
        
        if(newHead == NULL)// This means it's the first iteration
            newHead = prev; // Prev
            
        // Notice, in first iteration, we didn't have tail.
        // For example 
        
        if(tail != NULL)// We have a tail of previous linkedlist
            tail->next = prev;// Attach the damn lists.
        
        tail = preHead; 
        
    }
    return newHead;
}
