/*
Scan from left to right.
Postfix has pattern <operand1> <operand2> <operator>
We keep pushing the numbers into the stack. Whenever, we encounter an operator, we pop two latest numbers (LIFO, stack)
the first number popped is the second operand and the second number popped is the first operand. We do the operation and 
push them back into the stack.
In the end, we will have the result in the stack.

To check operator, use A[i].size() == 1. Depends on the input.
*/


int Solution::evalRPN(vector<string> &A) {
    
    stack<int> s;
    
    for(int i = 0; i < A.size(); i++)
    {
     
        if(!s.empty() && (A[i].size() == 1) && (A[i][0] == '/' || A[i][0] == '*' || A[i][0] == '+' || A[i][0] == '-') )
        {
            int b = s.top();
            s.pop();
            int a = s.top();
            s.pop();
            if(A[i][0] == '/')
            {
                s.push(a/b);
            }
            else if(A[i][0] == '*')
            {
                s.push(a*b);
            }
            else if(A[i][0] == '-')
            {
                s.push(a-b);
            }
            else if(A[i][0]== '+')
            {
                s.push(a+b);
            }
        }
        else if(A.size() >= 1) // Stoi makes life easier.
        {
            s.push(stoi(A[i]));
        }
        
    }
    return s.top();
}
