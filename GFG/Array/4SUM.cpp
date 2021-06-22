 vector<vector<int> > fourSum(vector<int> &arr, int k) {
    //Your Code Here
    int n  = arr.size();
    sort(arr.begin(), arr.end());
    vector<vector<int>> res;
    int X = k;
    for(int i = 0; i < n - 3; i++)
    {
        int first = arr[i];
        
        for(int j = i + 1; j < n - 2; j++)
        {
            int second = arr[j];
            int left = j + 1;
            int right = n - 1;
            while(left < right)
            {
                long long int sum = arr[left] + arr[right] + first + second ;
                int old_l = left;
                int old_r = right;
                if(sum  == X)
                {  
                    // vector<int> temp = {arr[left], arr[right], first, second}; 
                    vector<int> temp;
                    temp.push_back(first);
                    temp.push_back(second);
                    temp.push_back(arr[left]);
                    temp.push_back(arr[right]);
                    res.push_back(temp);
                   while (left < right && arr[left] == temp[2]) left++;
                    while (left < right && arr[right] == temp[3]) right--;
                  
                  
                }
                else if(sum < X)
                {
                    left++;
                }
                else if(sum > X)
                {
                    right--;
                }
            }
            while(j + 1 < n && arr[j] == arr[j + 1])j++;
            // stop one step back since j++ will do the job.
        }
        while(i + 1 < n && arr[i] == arr[i + 1])i++;
    }
    sort(res.begin(), res.end());
    return res;