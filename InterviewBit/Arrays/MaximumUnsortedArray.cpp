/*
This is the O(N) time and O(1) space complexity approach.
We search from the left side the left index where inversion happens
We search from the right side where the right inversion happens
Then, within this range, we check the maximum and the minimum.
Based on the maximum and minimum, we will get the correct bounds.
*/


vector<int> Solution::subUnsort(vector<int> &A) {
    
    int flag = 0;
    for(int i = 0; i < A.size() - 1; i++)
    {
        if(A[i+1] >= A[i])continue;
        else flag = 1;
    }
    if(flag == 0)return vector<int>{-1}; // Already sorted
    
    int left, right;
    int min_num, max_num;
    
    min_num = INT_MAX;
    max_num = INT_MIN;
    
    for(int i = 0; i < A.size() - 1; i++) // Find left inversion point
    {
        if(A[i+1] < A[i])
        {
            left = i;
            break;
        }
    }
    /* The above can be written in shortened way
    while(i + 1 < A.size() && A[i] <=  A[i + 1]) i++;
    */
    
    for(int i = A.size() - 1; i > 0; i--) // Find right inversion point
    {
        if(A[i] < A[i-1])
        {
            right = i ;
            break;
        }
    }
    
     for(int i = left; i <= right; i++) // Select the minimum and the maximum in that range to get correct bounds
     {
        max_num = max(max_num, A[i]);
        min_num = min(min_num, A[i]);
     }
    
    int final_left, final_right;
    
    for(int i = 0; i < A.size(); i++) // Just place them correctly
    {
        if(A[i] <= min_num)continue;
        else 
        {
            final_left = i;
            break;
        }
    }
    
    for(int i =  A.size() - 1; i >= 0; i--)
    {
        if(A[i] >= max_num)continue;
        else 
        {
            final_right = i;
            break;
        }
    }
    return vector<int>{final_left,final_right};
}
