**Quick sort**
```
Lomuto partition scheme
int partition(vector<int>& nums, int l, int r) 
{
    int p = random() % (r - l + 1);
    swap(nums[r], nums[r - p]);
    int pivot = r;
    for(int i = l ; i < r; i++)
    {
        if(nums[i] <= nums[pivot])
        {
            swap(nums[l++], nums[i]);
        }
    }
    swap(nums[pivot], nums[l]);
    return l;
}

void quick(vector<int>& nums, int low, int high)
{
	if(low < high)
	{
		int p = partition(nums, low, high);
		quick(nums, low, p - 1);
		quick(nums, p + 1, high);
	}
}
```
Hoare partition does not work in kth largest element. Prrobably some infinite recursion happens sometimes.
```
  int HoarePartition(vector<int>& nums, int l, int r)
    {
        int pivot = l;
        int i = l;
        int j = r;
        while(i<j)
        {
            while(nums[i] <= nums[pivot] )i++;
            while(nums[j] > nums[pivot] )j--;
            if(i < j)swap(nums[i], nums[j]);
        }
        swap(nums[j],nums[pivot]);
        return j;
    }
 ```
