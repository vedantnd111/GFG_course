#include <bits/stdc++.h>
using namespace std;

// (())))()
//
string balance(string st)
{
    stack<char> stack1;
    string res1, res2;
    for (int i = 0; i < st.length(); i++)
    {
        if (st[i] == '(')
        {
            stack1.push(st[i]);
        }
        else
        {
            if (!stack1.empty())
            {
                stack1.pop();
            }
            else
            {
                res1 += '(';
                // return false;
            }
        }
    }
    while (!stack1.empty())
    {
        res2 += ')';
        stack1.pop();
    }
    // return true;
    return (res1 + st + res2);
}

int main()
{
    string st;
    cin >> st;
    int n = st.length();
    cout << balance(st) << endl;
}