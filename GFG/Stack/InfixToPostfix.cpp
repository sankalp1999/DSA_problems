#include <bits/stdc++.h>
using namespace std;


int prec(char c) 
{ 
    if(c == '^') 
    return 3; 
    else if(c == '*' || c == '/') 
    return 2; 
    else if(c == '+' || c == '-') 
    return 1; 
    else
    return -1; 
} 

int main() {
	int t;
	cin >> t;
	while(t--)
	{
	    string s;
	    cin >> s ;
	    stack<char> mystack;
	    string res = "";
	    
	    for(char c : s)
	    {
	        if(c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
	        {
	            res += c;
	        }
	        else if(c == '(') // If left parenthesis, then just push.
	        {
	            mystack.push(c);
	        }
	        else if(c == ')') // We need to pop out everything till we reach the '('
	        {
	            while(!mystack.empty() && mystack.top() != '(')
	            {
                    res.push_back(mystack.top());	                
	                mystack.pop();
	            }
	            if(!mystack.empty())
	            mystack.pop(); // Removign the open parenthesis
	        }
	        else // Operator has been scanned.
	        {	
			
	            // If anything there in the stack having a higher precedence, we need to pop it out since we have reached it's boundary of influence.		
	            while(!mystack.empty() && ( prec(c) <= prec( mystack.top() ) )) // Better version is mystack.top() > c
	            {
	                res.push_back(mystack.top());
	                mystack.pop();
	            }
	            mystack.push(c);
	        }
	    }
	    while(!mystack.empty())
	    {
	        res.push_back(mystack.top());
	        mystack.pop();
	    }
	    cout << res << endl;
	    
	}
	return 0;
}
