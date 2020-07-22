int intersectPoint(Node* head1, Node* head2)
{
    int l1, l2;
    l1 = l2 = 0;
    Node* curr = head1;
    Node* curr2 = head2;
    while(curr)
    {
        curr = curr->next;
        l1++;
    }
    while(curr2)
    {
        curr2 = curr2->next;
        l2++;
    }
    curr = head1;
    curr2 = head2;
    if(l1 > l2)
    {
        while(l1-- > l2) curr = curr->next;
    }
    else if(l2 > l1)
    {
        while(l2-- > l1)curr2 = curr2->next;
    }
    while(curr && curr2)
    {
        if(curr == curr2)return curr->data;
        curr = curr->next;
        curr2 = curr2->next;
    }
    return -1;
    
}
