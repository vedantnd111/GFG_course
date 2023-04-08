#include <bits/stdc++.h>
using namespace std;

// frequency of array elements
// time=O(n) space=O(n)

void frequency(int arr[], int n)
{
    unordered_map<int, int> dict;
    for (int i = 0; i < n; i++)
    {
        dict[arr[i]]++;
    }
    for (auto pair : dict)
    {
        cout << "key=" << pair.first << "val=" << pair.second << endl;
    }
}
// union of two arrays
// time=O(m+n) space=O(n)
void intersection(int arr[], int brr[], int n, int m)
{
    // unordered_map<int> dict;
    unordered_set<int> dict;
    // vector<int> vect;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        dict.insert(arr[i]);
    }
    for (int i = 0; i < m; i++)
    {
        if (dict.find(brr[i]) != dict.end())
        {
            // vect.push_back(brr[i]);
            res++;
            dict.erase(brr[i]);
        }
    }
    cout << res << endl;
}
// union of two arrays
// time=O(n+m) space=O(n+m)
void unionArrays(int arr[], int brr[], int n, int m)
{
    unordered_set<int> dict;
    for (int i = 0; i < n; i++)
    {
        dict.insert(arr[i]);
    }
    for (int i = 0; i < m; i++)
    {
        dict.insert(brr[i]);
    }
    int res = dict.size();
}

bool isSum(int arr[], int n, int sum)
{
    unordered_set<int> dict;
    for (int i = 0; i < n; i++)
    {
        if (dict.find((sum - arr[i])) != dict.end())
        {
            return true;
        }
        dict.insert(arr[i]);
    }
    return false;
}

// subarray with 0 sum
// time=O(n)
bool subArraySum0(int arr[], int n)
{
    unordered_set<int> dict;
    int pre_sum = 0;
    for (int i = 0; i < n; i++)
    {
        pre_sum += arr[i];
        if (dict.find(pre_sum) != dict.end())
        {
            return true;
        }
        if (pre_sum == 0)
        {
            return true;
        }
        dict.insert(pre_sum);
    }
    return false;
}

// subaaray with given sum
// time=O(n) space=O(n)
bool subArraySum(int arr[], int n, int sum)
{
    unordered_set<int> dict;
    int pre_sum = 0;
    for (int i = 0; i < n; i++)
    {
        pre_sum += arr[i];
        if (dict.find(pre_sum - sum) != dict.end())
        {
            return true;
        }
        if (pre_sum == sum)
        {
            return true;
        }
        dict.insert(pre_sum);
    }
    return false;
}

// longest subarray with given prefix sum
// time=O(n) space=O(n)

int maxlen(int arr[], int n, int sum)
{
    int pre_sum = 0;
    // in map prefix sum will be key and its starting point will be value
    unordered_map<int, int> dict;
    int res = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        pre_sum += arr[i];
        if (pre_sum == sum)
        {
            res = max(res, i + 1);
        }
        if (dict.find((pre_sum - sum)) != dict.end())
        {
            res = max(res, i - dict.find((pre_sum - sum))->second);
        }
        else
        {
            dict.insert({pre_sum, i});
        }
    }
    return res;
}

// find the longest subarray with equal number of 0s and 1s
int longestO1Subarray(int arr[], int n)
{
    unordered_map<int, int> dict;
    int pre_sum = 0;
    int res = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        pre_sum += (arr[i] == 1 ? 1 : -1);
        if (pre_sum == 0)
        {
            res = max(res, i + 1);
        }
        if (dict.find(pre_sum) != dict.end())
        {
            res = max(res, i - dict.find((pre_sum))->second);
        }
        else
        {
            dict.insert({pre_sum, i});
        }
    }

    return res;
}

// longest common span with same sum in two binary arrays
//

int longestSpan(int arr[], int brr[], int n)
{
    int temp[n];
    for (int i = 0; i < n; i++)
    {
        temp[i] = (arr[i] - brr[i]);
    }
    maxlen(temp, n, 0);
}

// longest consecutive subsdequences
// time=O(nlogn)

// int longestConsecutive(int arr[], int n)
// {
//     sort(arr, arr + n);
//     int curr = 1, res = INT_MIN;
//     for (int i = 1; i < n; i++)
//     {
//         if ((arr[i] - arr[i - 1]) == 1)
//         {
//             curr++;
//         }
//         else
//         {
//             res = max(res, curr);
//             curr = 1;
//         }
//     }
//     return res;
// }

// time=O(n) space=O(n)
int longestCosecutiveEffician(int arr[], int n)
{
    unordered_set<int> dict;
    int curr = 1, res = INT_MIN, i = 0;
    for (i = 0; i < n; i++)
    {
        dict.insert(arr[i]);
    }
    i = 0, curr = 1;
    while (i < n)
    {
        if (dict.find(arr[i] - 1) == dict.end())
        {
            curr = 1;
            while (dict.find(arr[i] + curr) != dict.end())
            {
                // cout << "curr=" << curr << endl;
                curr++;
            }
            res = max(curr, res);
            curr = 1;
        }
        i++;
    }
    res = max(res, curr);
    return res;
}

void printMap(unordered_map<int, int> dict)
{
    for (auto it : dict)
    {
        cout << it.first << " " << it.second << endl;
    }
}

// count distinct elements in every windows
void distinctElements(int arr[], int n, int k)
{
    unordered_map<int, int> dict;
    int temp = 0;
    int first = 0, last = k - 1, j = 0;
    for (int i = 0; i < k; i++)
    {
        dict[arr[i]]++;
    }
    printMap(dict);
    cout << dict.size() << endl;
    for (int j = k; j < n; j++)
    {
        dict[arr[first]]--;
        temp = dict[arr[first]] == 0 ? -1 : 0;
        first++;
        dict[arr[j]]++;
        printMap(dict);
        cout << "len=" << dict.size() + temp << endl;
    }
}

// more than n/k occurances in a number
// it is a modified form of moorays voting algorithm

void moreThanNK(int arr[], int n, int k)
{
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        if (m.find(arr[i]) != m.end())
        {
            m[arr[i]]++;
        }
        else if (m.size() < (k - 1))
        {
            m.insert({arr[i], 1});
        }
        else
        {
            cout << "else\n";
            for (auto it : m)
            {
                it.second--;
                // if (it.second == 0)
                // {
                //     m.erase(it.first);
                // }
            }
        }
    }
    for (auto it : m)
    {
        if (it.second > (n / k))
        {
            cout << (it.first) << " ";
        }
    }
    cout << "\n";
}

int main()
{
    int n, x;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        arr[i] = x;
    }
    // int k;
    // cin >> k;
    // cout << subArraySum(arr, n, sum) << endl;
    // cout << maxlen(arr, n, sum) << endl;
    // cout << longestO1Subarray(arr, n) << endl;
    // cout << longestSpan(arr, brr, n) << endl;
    // cout << longestConsecutive(arr, n) << endl;
    // cout << longestCosecutiveEffician(arr, n) << endl;
    // distinctElements(arr, n, k);
    // moreThanNK(arr, n, k);
}