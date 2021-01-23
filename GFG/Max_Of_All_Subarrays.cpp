vector <int> max_of_subarrays(int *arr, int n, int k){
    // your code here
    deque<int> dq;
    vector<int> res;
    // Store the indices to keep track of the window
    for(int i = 0; i < k; i++)
    {
        while(!dq.empty() && arr[i] > arr[dq.back()])
        {
            dq.pop_back();
        }
        dq.push_back(i);
        
    }
    res.push_back(arr[dq.front()]);
    for(int i = k; i < n; i++)
    {
        while( !dq.empty() && arr[i] > arr[dq.back()]) // remove the smaller ones since we are trying to maintain only the bigger elements
        {
            dq.pop_back();
        }
        while( !dq.empty() && i - dq.front() >= k) // See if the indices are still valid or not.
        {
            dq.pop_front();
        }
         dq.push_back(i);
        res.push_back(arr[dq.front()]);
    }
    return res;
    
}
