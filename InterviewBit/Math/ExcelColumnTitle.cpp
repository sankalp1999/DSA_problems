string Solution::convertToTitle(int A) {
    string title = "";
    stack<int> s;
    while(A!=0)
    {
        int rem = A%26;
        if(rem == 0) // Handle the case when rem ==0 because in the 
        // given mapping, A = 26 gives Z. Also, the 26/26 = 1. Hence, loop
        // will run one more time. That was the catch in this question
        
        //Alternatively, A = (A - 1)/26 can solve the problem.
        {
            s.push(26);
            A = A/26 - 1;
        }
        else
        {
            s.push(rem);
            A = A/26;
        }
            
        }
    while(!s.empty())
    {
        title += ('A' + s.top() - 1);
        s.pop();
    }
    return title;
}

/*Editorial Solution*/
string convertToTitle(int n) {
    string ans;
    while (n) {
        ans = char ((n - 1) % 26 + 'A') + ans; // Add from front and handle A = 26 case.
        n = (n - 1) / 26;
    }
    return ans;
}






