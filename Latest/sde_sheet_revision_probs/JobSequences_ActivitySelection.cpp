class Solution 
{
    
    public:
    //Function to find the maximum profit and the number of jobs done.
    
    static bool compare(Job& a, Job& b)
    {
        return a.profit > b.profit;
    }
    
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr, arr + n, compare);
        int visited[105] = {0};
        long long int count = 0;
        int jobs = 0;
        for(int i = 0; i < n; i++)
        {
            int dl = arr[i].dead;
            int flag = 0;
            for(int j = dl; j >= 1; j--)
            {
                if(!visited[j])
                {   
                    count += arr[i].profit;
                    jobs++;
                    visited[j]=1;
                    break;
                }
            }
        }
        vector<int> res;
        res = {jobs,count};
        return res ;
    } 
