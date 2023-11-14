/*Given an array and a positive integer k, find the first negative integer for each and every window(contiguous subarray) of size k.
Example:
Input:
2
5
-8 2 3 -6 10
2
8
12 -1 -7 8 -15 30 16 28
3
Output:
-8 0 -6 -6
-1 -1 -7 -15 -15 0*/
#include <bits/stdc++.h>
using namespace std;

vector<int> firstNegativeNumberInEveryWindowOfSizeK(int arr[], int n, int k, vector<int> &v)
{
    int i = 0;
    int j = 0;

    list<int> l;

    while (j < n)
    {
        if (arr[j] < 0)
        {
            l.push_back(arr[j]);
        }
        if (j - i + 1 < k)
        {
            j++;
        }
        else if (j - i + 1 == k)
        {
            if (l.empty())
            {
                v.push_back(0);
            }
            else
            {
                v.push_back(l.front());
                if (arr[i] == l.front())
                {
                    l.pop_front();
                }
            }
            i++;
            j++;
        }
    }
    return v;
}

int main()
{
    int arr[] = {-8, 2, 3, -6, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;

    vector<int> v;

    v = firstNegativeNumberInEveryWindowOfSizeK(arr, n, k, v);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}