/*Given an array arr[] of size N and an integer K. Find the maximum for each and every contiguous subarray of size K.
Example:
Input 1:
A = [1, 3, -1, -3, 5, 3, 6, 7]
B = 3
Output 1:
C = [3, 3, 5, 5, 6, 7]
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> maxOfAllSubarraysOfSizeK(int arr[], int n, int k)
{
    int i = 0;
    int j = 0;
    vector<int> ans;
    list<int> l;

    if (k > n)
    {
        ans.push_back(*max_element(arr, arr + n));
        return ans;
    }

    while (j < n)
    {
        while (l.size() > 0 && l.back() < arr[j])
        {
            l.pop_back();
        }
        l.push_back(arr[j]);

        if (j - i + 1 < k)
        {
            j++;
        }
        else if (j - i + 1 == k)
        {
            ans.push_back(l.front());

            if (l.front() == arr[i])
            {
                l.pop_front();
            }
            i++;
            j++;
        }
    }
    return ans;
}

int main()
{
    int arr[] = {1, 3, -1, -3, 5, 3, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    vector<int> v = maxOfAllSubarraysOfSizeK(arr, n, k);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    // Brute-Force
    /*int max;

    for (int i = 0; i < n - k + 1; i++)
    {
        max = arr[i];
        for (int j = 1; j < k; j++)
        {
            if (arr[i + j] > max)
            {
                max = arr[i + j];
            }
        }
        cout << max << " ";
    }*/

    return 0;
}