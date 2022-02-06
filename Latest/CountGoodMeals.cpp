// Extension of 2 sum problem
// Finding the ceil was important to pass tight time limit


class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        vector<int> arr = deliciousness;
        int n = arr.size();
        int res = 0;
        const int mod = 1e9 + 7;
        int maxi = ceil(log2(*max_element(arr.begin(), arr.end())));

        for(int i = 0; i < maxi+  2; i++)
        {
            long int target = (1 << i);
            unordered_map<int,int> mapper;
            for(int j = 0; j < n; j++)
            {
                long int k = target - arr[j];
                if(mapper.find(k) != mapper.end())
                {
                    int sum = mapper[k];
                    res = ( (res % mod) + (sum % mod) ) %mod;
                }
                mapper[arr[j]]++;
            }
        }
        return res;
    }
};
