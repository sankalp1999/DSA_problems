/*
If number, push in stack.
If operator encountered, then pop out the operands i.e 2 elements
<Operand 2> <Operand 1> < Operator >
That is why we use a stack so that we can get the last going in element first.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int t;
	cin >> t;
	while(t--)
	{
	    string s;
	    cin >> s;
	    stack<long long int> mystack;
	    for(char c : s)
	    {
	        if(c >= '0' && c <= '9')
	        {
	            mystack.push(c - '0');
	        }
	        else if(c == '+' || c == '-' || c == '/' || c == '*')
	        {
	            int b = mystack.top();
	                
                if(!mystack.empty())
                mystack.pop();
	                
                int a = mystack.top();
                
                if(!mystack.empty())
                mystack.pop();
                
	            if(c == '+')
	            {
	                mystack.push(a + b);    
	            }
	            else if(c == '-')
	            {
	                mystack.push(a - b);    
	            }
	            else if(c == '*')
	            {
	                mystack.push(a * b);    
	            }
	            else if(c == '/')
	            {
	                mystack.push(a / b);    
	            }
	            
	        }
	    }
	    cout << mystack.top() << endl;
	}
	return 0;
}
