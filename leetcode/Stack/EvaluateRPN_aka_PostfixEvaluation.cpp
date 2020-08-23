class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        
        stack<int> s;
        for(int i = 0; i < tokens.size(); i++)
        {
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"  )
            {
                int b = s.top(); // Most important operand 2
                s.pop();
                int a = s.top(); // operand 1 since it's LIFO
                s.pop();
                if(tokens[i] == "+")
                {
                    s.push(a + b);
                }
                 else if(tokens[i] == "-")
                {
                    s.push(a - b);
                }
                 else if(tokens[i] == "*")
                {
                    s.push(a * b);
                }
                 else if(tokens[i] == "/")
                {
                    s.push(a / b);
                }
            }
            else
            {
                s.push(stoi(tokens[i]));
            }
        }
        return s.top();
    }
};
