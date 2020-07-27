/*
This is the solution using the hare and tortoise algorithm.
We can imagine the array elements to link to the indexes of the array (equal to their values). So, here
if we run two pointers, they will intersect sometime in the future.
Now, when they intersect, we set one of them to the head again. Now, we let them run
at the same speed (tortoise speed). The next time they will intersect, that is going 
to be the duplicate
*/
int Solution::repeatedNumber(const vector<int> &nums) {
   
    int slow = nums[0];
    int fast = nums[0];
    while(1)
    {
        slow = nums[slow];
        fast = nums[nums[fast]];
        if(fast == slow)break;
    }
    slow = nums[0];
    while(slow!= fast)
    {
        slow = nums[slow];
        fast = nums[fast];
        if(slow == fast)return fast;
    }
    if(slow == fast)return fast;
    return -1;
}
