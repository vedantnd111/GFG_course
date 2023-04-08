#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// find the index of an element in sorted array
// time=O(logn) space=O(1)

int binary_search(int arr[], int low, int high, int x)
{
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == x)
        {
            return mid;
        }
        else if (arr[mid] > x)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}

// return the last occurance of given element in array
int binary_search_last_occurance(int arr[], int low, int high, int x)
{
    int mid;
    int n = high;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (arr[mid] > x)
        {
            high = mid - 1;
        }
        else if (arr[mid] < x)
        {
            low = mid + 1;
        }
        else
        {
            if (mid == n || arr[mid] != arr[mid + 1])
            {
                return mid;
            }
            else
            {
                low = mid + 1;
            }
        }
        /* code */
    }
    return -1;
}

// return the last occurance of given element in array
int binary_search_first_occurance(int arr[], int low, int high, int x)
{
    int mid;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (arr[mid] == x)
        {
            if (mid > 0 && (arr[mid - 1] == x))
            {
                high = mid - 1;
            }
            else
            {
                return mid;
            }
        }
        else if (arr[mid] < x)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int search_in_sorted_rotated_array(int arr[], int low, int high, int x)
{
    int mid;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (arr[mid] == x)
        {
            return mid;
        }
        if (arr[mid] > arr[0])
        {
            if ((x >= arr[0]) && (x < arr[mid]))
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        else
        {
            if ((x > arr[mid + 1]) && (arr[high] >= x))
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return -1;
}

// first and last element are always peak elemnts
int find_peak(int arr[], int low, int high)
{
    int mid;
    int n = high;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if ((mid == 0 || arr[mid] >= arr[mid - 1]) && (mid == n || arr[mid] >= arr[mid + 1]))
        {
            return arr[mid];
        }
        if (mid > 0 && arr[mid - 1] >= arr[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
}

int median_of_two_sorted_array(int arr1[], int arr2[], int n1, int n2)
{
    int begin1 = 0, end1 = n1, i1, i2, max1, min1, max2, min2;
    while (begin1 <= end1)
    {
        i1 = begin1 + (end1 - begin1) / 2;
        i2 = ((n1 + n2 + 1) / 2) - i1;
        min1 = i1 == n1 ? INT_MAX : arr1[i1];
        max1 = i1 == 0 ? INT_MIN : arr1[i1 - 1];
        min2 = i2 == n2 ? INT_MAX : arr2[i2];
        max2 = i2 == 0 ? INT_MIN : arr2[i2 - 1];
        if ((min1 >= max2) && (min2 >= max1))
        {
            cout << "1st\n";
            if (((n1 + n2) % 2) == 0)
            {
                // cout << "even =" << max(max1, max1) + (double)min(min1, min2) << endl;

                return (double)(((double)max(max1, max2) + (double)min(min1, min2)) / 2);
            }
            else
            {
                cout << "odd\n";
                return (double)(max(max1, max2));
            }
        }
        else if ((max1 > min2))
        {
            cout << "2nd\n";
            end1 = i1 - 1;
        }
        else
        {
            cout << "3rd\n";
            begin1 = i1 + 1;
        }
    }
    return -1;
}

// we are given an array which contain elements from 0 to n-1 and only one element occurs more than one in it find that element
// O(n) time and O(1) space
int repeating_element(int arr[], int n)
{
    int slow = arr[0] + 1, fast = arr[0] + 1;
    do
    {
        slow = arr[slow] + 1;
        fast = arr[arr[fast] + 1] + 1;
    } while (slow != fast);
    slow = arr[0] + 1;
    do
    {
        slow = arr[slow] + 1;
        fast = arr[fast] + 1;
    } while (slow != fast);
    return slow - 1;
}

int sum(int arr[], int s, int e)
{
    int su = 0;
    for (int i = s; i <= e; i++)
    {
        su += arr[i];
    }
    return su;
}

// naive solution(exponential)
// find min pages a student will read
int allocate_minpages(int arr[], int n, int k)
{
    if (k == 1)
    {
        return sum(arr, 0, n - 1);
    }
    if (n == 1)
    {
        return arr[0];
    }
    int res = INT_MAX;
    for (int i = 1; i < n; i++)
    {
        res = min(res, max(allocate_minpages(arr, i, k - 1), sum(arr, i, n - 1)));
    }
}

// O(n) time
bool isFisible(int arr[], int n, int mid, int k)
{
    // check how many students will be needed if each student reads mid pages
    int req = 0, s1 = 0;
    for (int i = 0; i < n; i++)
    {
        if ((s1 + arr[i]) > mid)
        {
            req++;
            s1 = arr[i];
        }
        else
        {
            s1 += arr[i];
        }
    }
    if (req > k)
    {
        return false;
    }
    else
    {
        return true;
    }
}

// total O(nlog(sum))
int allocate_minpages_efficiant(int arr[], int n, int k)
{
    int max1 = INT_MIN, sum = 0;
    for (int i = 0; i < n; i++)
    {
        max1 = max(max1, arr[i]);
        sum += arr[i];
    }
    int low = max1, high = sum, mid, res = INT_MIN;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (isFisible(arr, n, mid, k))
        {
            // if mid is fissible,we want to check on left of mid
            res = max(res, mid);
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return res;
}

// search in infinite sized array
int search_infinite_sized_array(int arr[], int n, int x)
{
    int low = 0, high = n, mid;
    if (arr[0] == x)
    {
        return 0;
    }
    else
    {
        low = 1, high = 2 * low;
        while (low <= high)
        {
            if (x < arr[high])
            {
                mid = low + (high - low) / 2;
                if (arr[mid] == x)
                {
                    return mid;
                }
                else if (arr[mid] > x)
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            else if (x > arr[high])
            {
                low = high;
                high = 2 * high;
            }
            else
            {
                return high;
            }
        }
        return -1;
    }
}

// infinite sized array solution from gfg
int infinite_sized_array_gfg(int arr[], int n, int x)
{
    if (arr[0] == x)
    {
        return 0;
    }
    int i = 1;
    while (arr[i] < x)
    {
        i = i * 2;
        if (arr[i] == x)
        {
            return i;
        }
    }
    return binary_search(arr, i / 2 + 1, i, x);
}

// square root using binary search O(logn) time
int square_root(int num)
{
    int low = 1, high = num, mid, res;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (mid * mid == num)
        {
            return mid;
        }
        else if (mid * mid < num)
        {
            res = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return res;
}

int main()
{
    int n1, n2, x, k;
    cin >> n1;
    int arr1[n1];
    for (int i = 0; i < n1; i++)
    {
        cin >> x;
        arr1[i] = x;
    }
    int ele;
    cout << "element to be searched\n";
    cin >> ele;
    int ans = binary_search_first_occurance(arr1, 0, n1 - 1, ele);
    // int ans = binary_search_last_occurance(arr, 0, n - 1, ele);
    // int ans = search_in_sorted_rotated_array(arr, 0, n - 1, ele);
    // int ans = find_peak(arr, 0, n - 1);
    // int ans = median_of_two_sorted_array(arr1, arr2, n1, n2);
    // int ans = repeating_element(arr1, n1);
    // int ans = allocate_minpages_efficiant(arr1, n1, k);
    // int num;
    // cin >> num;
    // int ans = square_root(num);
    cout << "ans=" << ans << endl;
    return 0;
}