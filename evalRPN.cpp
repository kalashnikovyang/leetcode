class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        int len = tokens.size();
        
        stack<int> s;
        
        int i,j;
        int a,b;
        for(i=0;i<len;i++)
        {
            if(tokens[i] == "+")
            {
                a = s.top();
                s.pop();
                b = s.top();
                s.pop();
                s.push(b+a);
            }
            else if(tokens[i] == "-")
            {
                a = s.top();
                s.pop();
                b = s.top();
                s.pop();
                s.push(b-a);
            }
            else if(tokens[i] == "*")
            {
                a = s.top();
                s.pop();
                b = s.top();
                s.pop();
                s.push(b*a);
            }
            else if(tokens[i] == "/")
            {
                a = s.top();
                s.pop();
                b = s.top();
                s.pop();
                s.push(b/a);
            }
            else
            {
                // turn string to numbers, "-123" -> -123
                int l = tokens[i].length();
                int value = 0;
                int flag = 0;
                if(tokens[i][0] == '-')
                {
                    flag = 1; //negative number
                }
                for(j=flag;j<l;j++)
                {
                   int temp = (int)(tokens[i][j] - '0');
                   value = value*10 + temp;
                }
                if(flag == 1) value = -value;
                s.push(value);
            }
        }
        
        return s.top();
        
    }
};