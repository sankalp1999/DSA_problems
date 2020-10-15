
/* If we select smallest of k entries at each step, we are guaranteed to 
get a sorted list
*/

/* To make min priority queue */
struct Compare { 
    bool operator()(Node* const& p1, Node* const& p2) 
    { 
        // return "true" if "p1" is ordered  
        // before "p2", for example: 
        return p1->data > p2->data; 
    } 
}; 

Node * mergeKLists(Node *arr[], int N)
{
      priority_queue<Node*,vector<Node*>, Compare > pq;
      Node* temp = new Node(0);
      Node* dummy = temp;
    int k = N;
    int flag = 0;
    while(1) // 
    {
          flag = 0;
          for(int i = 0; i < k ;i++)
          {
              if(arr[i] != NULL)
              {
                  flag = 1;
                  pq.push(arr[i]);
                  arr[i] = arr[i]->next;
              }
              // Else continue
          }
         if(pq.size() > k)
         {
             Node* top = pq.top();
             pq.pop();
             temp->next = top;
             temp = temp->next;
         }
         if(flag == 0) // This means we are done with all lists
            break;
    } 
    while(!pq.empty())
    {
        auto top = pq.top();
        pq.pop();
        temp->next = top;
        temp = temp->next;
    }
    temp->next = NULL;
    
    return dummy->next;
}
