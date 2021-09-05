class Solution {
public:
    string removeKdigits(string num, int k) {
        int count = 0;
        
        while(count < k)
        {   
            int flag = 0;
            for(int i = 0; i < num.size() - 1; i++)
            {
                if(num[i] - '0' > num[i+1] - '0' and count < k) // Observation : When we remove a digit which is greater than next digit, reduction happens.
                {
                    num.erase(i,1);
                    i--;
                    flag = 1;
                    break;
                }
            }
            if(flag == 0)
            {
                num.erase(num.size() - 1, 1);
            }
            count++;
        }

        int i = 0;
        while(num[i] == '0')i++;
        string temp = "";
        while(i<num.size())temp += num[i++];
        if(temp == "")
            return "0";
        return temp;
    }
};
// "1 3 2219"
