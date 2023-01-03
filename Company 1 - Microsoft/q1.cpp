#include <bits/stdc++.h>
using namespace std;

// You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

// Evaluate the expression. Return an integer that represents the value of the expression.
int evalRPN(vector<string> &tokens)
{
    stack<int> st;
    for (string &s : tokens)
    {
        // push all the integers into the stack
        if (s.size() > 1 || isdigit(s[0]))
            st.push(stoi(s));
        else
        {
            //accounting for encountering an operation
            int temp2 = st.top();
            st.pop();
            int temp1 = st.top();
            st.pop();
            switch (s[0])
            {
            case '+':
                temp1 += temp2;
                break;
            case '-':
                temp1 -= temp2;
                break;
            case '/':
                temp1 /= temp2;
                break;
            case '*':
                temp1 *= temp2;
                break;
            }
            //push the new number into the stack
            st.push(temp1);
        }
    }
    return st.top();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    return 0;
}