/*
You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

Evaluate the expression. Return an integer that represents the value of the expression.

Note that:
    *The valid operators are '+', '-', '*', and '/'.
    *Each operand may be an integer or another expression.
    *The division between two integers always truncates toward zero.
    *There will not be any division by zero.
    *The input represents a valid arithmetic expression in a reverse polish notation.
    *The answer and all the intermediate calculations can be represented in a 32-bit integer.
*/


class Solution {
public:
    bool isOperator(string ch) {
        if(ch=="+" || ch=="-" || ch=="*" || ch=="/") 
        {
            return true;
        }
        return false;
    }
    
    int evalRPN(vector<string>& s) {
        stack<long long>st;
        for(int i=0;i<s.size();i++) 
        {
            if(isOperator(s[i])) 
            {
                long long a=st.top();
                st.pop();
                long long b=st.top();
                st.pop();
                if(s[i]=="+")
                {
                    long long c=b+a;
                    st.push(c);
                }
                else if(s[i]=="-")
                {
                    long long c=b-a;
                    st.push(c);
                }
                else if(s[i]=="*")
                {
                    int c=b*a;
                    st.push(c);
                }
                else if(s[i]=="/")
                {
                    long long c=b/a;
                    st.push(c);
                }
            }
            else
            {
                st.push(stoi(s[i]));
            }
        }
        return st.top();
    }
};