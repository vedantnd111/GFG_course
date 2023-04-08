#include <bits/stdc++.h>
using namespace std;

// string convert(string s, int numRows)
// {
//     int temp = numRows - 1;
//     int j = 0, i = 0;
//     // cout << s.length() << endl;
//     string res;
//     while (i < numRows)
//     {
//         // cout << "outer\n";
//         j = i;
//         while (j < s.length())
//         {
//             // cout << "inner\n";
//             res += s[j];
//             // cout << "j=" << j << endl;
//             if (temp == 0)
//             {
//                 j +=(numRows+1);
//             }
//             else
//             {
//                 j = j + 2 * temp;
//             }
//         }
//         i++;
//         temp--;
//     }
//     cout << res << endl;
// }

bool isAlpha(char ch)
{
    if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool isNum(char ch)
{
    if (ch >= '0' && ch <= '9')
    {
        return true;
    }
    else
    {
        return false;
    }
}

int convert(char ch)
{
    return (int)ch - 48;
}

long long int myAtoi(string s)
{
    string res;
    long long int ans = 0;
    int numIndex, count = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (isNum(s[i]))
        {
            count++;
            if (count == 1)
            {
                numIndex = i;
                ans += convert(s[i]);
            }
            else
            {
                ans = (ans * 10) + convert(s[i]);
            }
        }
    }
    bool minus = s[numIndex - 1] == '-' ? true : false;
    if (minus)
    {
        return -1 * ans;
    }
    else
    {
        return ans;
    }
}

int main()
{
    string s;
    cin >> s;
    cout << myAtoi(s) << endl;
}