class Solution {
public:
    vector<int> countBits(int num) {
        int count = 0;
        vector<int> res;
        
    for(int i = 0; i <= num; i++)
    {
        long long int x =i;
        count = 0;
        
        while(x>0)
        {
            x = (x) & (x - 1);
            count++;
        }
        
        res.push_back(count);
    }   
        return res;
    }
};
