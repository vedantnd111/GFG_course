#include <bits/stdc++.h>
using namespace std;

void c_style_string()
{
    // char st[] = {'g', 'f', 'g','\0'};
    char st[] = {'g', 'f', 'g'}; // it will print garbage characters at the end
    cout << st << endl;
    for (int i = 0; i < strlen(st); i++)
    {
        cout << st[i] << " ";
    }
    cout << endl;
}

bool compare(string text, string pat, int start, int end)
{
    int j = 0;
    for (int i = start; i < end; i++)
    {
        if (pat[j] == text[i])
        {
            j++;
        }
        else
        {
            return false;
        }
    }
    return true;
}
// time=O((n-m+1)*m)
void naive_pattern_printing()
{
    string text, pat;
    cin >> text >> pat;
    for (int i = 0; i <= (text.length() - pat.length()); i++)
    {
        bool flag = compare(text, pat, i, i + pat.length());
        if (flag)
        {
            cout << i << " ";
        }
    }
    cout << endl;
}

// naive pattern searching algo when there are only distinct elements
// time=O(n)
void naive_pattern_searching_distinct()
{
    string text, pat;
    cin >> text >> pat;
    int n = text.length(), m = pat.length();
    for (int i = 0; i <= (n - m);)
    {
        int j = 0;
        for (j = 0; j < m; j++)
        {
            if (pat[j] != text[i + j])
            {
                break;
            }
        }
        if (j == m)
        {
            cout << i << " ";
        }
        if (j == 0)
        {
            i++;
        }
        else
        {
            i = (i + j);
        }
    }
}

// Rabin karp algorithm
// using hash function as alphabet sum
void rabin_karp()
{
    string text, pat;
    cin >> text >> pat;
    int n = text.length();
    int m = pat.length();
    int window_hash = 0, pat_hash = 0;
    for (int i = 0; i < m; i++)
    {
        window_hash += (int)(text[i] - 'a' + 1);
        pat_hash += (int)(pat[i] - 'a' + 1);
    }
    if (window_hash == pat_hash)
    {
        cout << "0 ";
    }
    for (int i = 1; i <= n - m; i++)
    {
        window_hash += ((int)text[i + m - 1] - (int)text[i - 1]);
        if (window_hash == pat_hash)
        {
            bool flag = compare(text, pat, i, i + m);
            if (flag)
            {
                cout << i << " ";
            }
        }
    }
}

// using an efficiant hash function
// m be the length of the pattern
// hash=pat[0]*d^(m-1)+pat[1]*d(m-2)+...+pat[m-1]*d^(0)
// finding out hash value of next pattern
// hash_next=d*(hash_prev-text[i]*(d^(m-1)))+text[i+m]

// worst case complexity = (O((n-m+1)*m))
// worst case arrives when text==aaaaaa and pat=aaa
// in this type of cases it does work more than naive algorithm

// it is used when we have multiple patterns in the text
void rabin_karp_improved()
{
    string text, pat;
    cin >> text >> pat;
    int n = text.length();
    int m = pat.length();
    int window_hash = 0, pat_hash = 0, d = 5;
    // calculating d^(m-1)
    int h = 1;
    for (int i = 1; i <= m - 1; i++)
    {
        h = h * d;
    }
    long long int q = pow(10, 9) + 7;
    // calcualting hash value of pattern and window
    for (int i = 0; i < m; i++)
    {
        pat_hash = (pat_hash * d + pat[i]) % q;
        window_hash = (window_hash * d + text[i]) % q;
    }
    for (int i = 0; i <= n - m; i++)
    {
        if (pat_hash == window_hash)
        {
            bool flag = true;
            for (int j = 0; j < m; j++)
            {
                if (pat[j] != text[i + j])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                cout << i << " ";
            }
        }
        // calcualte hash value for next window
        if (i < (n - m))
        {
            window_hash = (d * (window_hash - text[i] * h) + text[i + m]) % q;
            if (window_hash < 0)
            {
                window_hash = (window_hash + q);
            }
        }
    }
}

int longestProperPrefix(string st, int n)
{
    for (int len = n - 1; len > 0; len--)
    {
        bool flag = true;
        for (int i = 0; i < len; i++)
        {
            if (st[i] != st[n - len + i])
            {
                flag = false;
            }
        }
        if (flag == true)
        {
            return len;
        }
    }
    return 0;
}

// finding out lps array
// naive
// time=O(n^3)
void fill_lps()
{
    string st;
    cin >> st;
    int n = st.length();
    int lps[n];
    for (int i = 0; i < n; i++)
    {

        lps[i] = longestProperPrefix(st, i + 1);
    }
    for (int i = 0; i < n; i++)
    {
        cout << lps[i] << " ";
    }
    cout << endl;
}

void fill_lps_improved(int lps[], string st)
{
    int n = st.length();
    // int lps[n];
    lps[0] = 0;
    int len = 0, i = 1;
    while (i < n)
    {
        if (st[i] == st[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
            else
            {
                len = lps[len - 1];
            }
        }
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << lps[i] << " ";
    // }
    // cout << endl;
}

// time=O(n)
void kmp()
{
    string text, pat;
    cin >> text >> pat;
    int n = text.length();
    int m = pat.length();
    int lps[m];
    fill_lps_improved(lps, pat);
    int i = 0, j = 0;
    while (i < n)
    {
        // cout << "i=" << i << endl;
        if (pat[j] == text[i])
        {
            i++;
            j++;
        }
        if (j == m)
        {
            cout << (i - j) << " ";
            j = lps[j - 1];
        }
        else if (j < m && pat[j] != text[i])
        {
            if (j == 0)
            {
                i++;
            }
            else
            {
                j = lps[j - 1];
            }
        }
    }
}

bool compareArrays(int arr[], int brr[])
{
    for (int i = 0; i < 256; i++)
    {
        if (arr[i] != brr[i])
        {
            return false;
        }
    }
    return true;
}

bool areAnagrams()
{
    string text, pat;
    cin >> text >> pat;
    int n = text.length();
    int m = pat.length();
    int text_count[256] = {0}, pat_count[256] = {0};
    for (int i = 0; i < m; i++)
    {
        text_count[text[i]]++;
        pat_count[pat[i]]++;
    }
    for (int i = m; i < n; i++)
    {
        if (compareArrays(text_count, pat_count))
        {
            return true;
        }
        text_count[text[i]]++;
        text_count[text[i - m]]--;
    }
    return false;
}

// lexicographical rank of the string
int factorial(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
        return n * (factorial(n - 1));
    }
}

// time=O(n+256+256+n*256)=O(n*256) ,space=O(256)
void lexicongraphic_rank()
{
    string st;
    cin >> st;
    string temp = st;
    int n = st.length();
    int arr[n] = {1};
    int count[256] = {0};
    for (int i = 0; i < n; i++)
    {
        count[(int)st[i]]++;
    }
    for (int i = 1; i < 256; i++)
    {
        count[i] += count[i - 1];
    }
    int ans = factorial(n);
    int t, res = 1;
    for (int i = 0; i < n - 1; i++)
    {
        ans = ans / (n - i);
        res += (ans * count[st[i] - 1]);
        for (int j = (int)st[i]; j < 256; j++)
        {
            count[j]--;
        }
    }
    cout << "res=" << res << endl;
}
void printArray(vector<int> arr)
{
    for (int i = 0; i < 26; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

bool areIsomorphic(string str1, string str2)
{
    int arr[256] = {0}, brr[256] = {0};
    if (str1.length() != str2.length())
    {
        return false;
    }
    else
    {
        for (int i = 0; i < str1.length(); i++)
        {
            if (arr[(int)str1[i]] && (arr[(int)str1[i]] != ((int)str2[i])))
            {
                return false;
            }
            else if (!arr[(int)str1[i]])
            {
                if (!brr[(int)str2[i]])
                {
                    arr[(int)str1[i]] = (int)str2[i];
                    brr[(int)str2[i]] = (int)str1[i];
                }
                else
                {
                    return false;
                }
            }
        }
        // printArray(arr,256);
        // printArray(brr,256);
        return true;
    }
    // Your code here
}

char firstRep(string s)
{
    // int arr[26]={-1};
    vector<int> vect(26, -1);
    int min1 = INT_MAX;
    // printArray(vect);
    for (int i = 0; i < s.length(); i++)
    {
        cout << s[i] << " val=" << vect[(int)s[i] - 97] << endl;
        if (vect[(int)s[i] - 97] > (-1))
        {
            // cout<<"min1="<<s[i]<<" "<<min1<<endl;
            min1 = min(min1, vect[(int)s[i] - 97]);
            cout << "min1=" << min1 << endl;
        }
        else if (vect[(int)s[i] - 97] == -1)
        {
            vect[(int)s[i] - 97] = i;
            ;
        }
    }
    return min1 != INT_MAX ? s[min1] : '-1';
    //code here.
}

void reverseWordByWord(string st)
{
    int n = st.length();
    int start = 0, end = 0;
    char temp;
    for (int i = 0; i < n; i++)
    {
        if (st[i] == ' ')
        {
            end = i - 1;
            // reverse(st,start,end);
            while (start < end)
            {
                temp = st[start];
                st[start] = st[end];
                st[end] = temp;
                start++;
                end--;
            }
            start = i + 1;
        }
    }
    end = n - 1;
    while (start < end)
    {
        temp = st[start];
        st[start] = st[end];
        st[end] = temp;
        start++;
        end--;
    }
    // cout << "op=" << st << endl;
    start = 0;
    end = n - 1;
    while (start < end)
    {
        temp = st[start];
        st[start] = st[end];
        st[end] = temp;
        start++;
        end--;
    }
    cout << st << endl;
}
// sa rep selur
// rules per as

int main()
{
    // c_style_string();
    // naive_pattern_printing();
    // naive_pattern_searching_distinct();
    // rabin_karp();
    // rabin_karp_improved();
    // fill_lps_improved();
    // kmp();
    // cout << areAnagrams() << endl;
    // lexicongraphic_rank();
    string s1;
    // cin >> s1;
    getline(cin, s1);
    // cout << firstRep(s1) << endl;
    reverseWordByWord(s1);
}