class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> res;
  
        if(n % 2)
        {   
           int start = 0 - n + 2;
            n--;
            while(n--)
            {
                res.push_back(start);
                start += 2;
            }
            res.push_back(0);
        }
        else
        {
            int start = n * -1 / 2;
            while(n--)
            {
                res.push_back(start);
                start++;
                if(start==0)start++;
            }
        }
        return res;
    }
};
