/*Given an array of integers Arr of size N and a number K. Return the maximum sum of a subarray of size K.
Example:
Input:
N = 4, K = 2
Arr = [100, 200, 300, 400]
Output:
700
Explanation:
Arr3  + Arr4 =700,
which is maximum.*/
#include <bits/stdc++.h>
using namespace std;

int maxSumSubarrayOfSizeK(int arr[], int n, int k)
{
    int i = 0; // start of window
    int j = 0; // end of window
    int sum = 0;
    int mx = INT_MIN;

    // for every sliding window problem of given size K these step is same
    while (j < n)
    {
        sum = sum + arr[j]; // 1 step -> doing calculations here bcoz we do not want O(n^2) solution.
        if (j - i + 1 < k)  // j - i + 1 -> stores the size of all windows in array
        {
            j++;
        }
        else if (j - i + 1 == k)
        {
            // 2 step -> making ans from calculation
            mx = max(mx, sum);
            sum = sum - arr[i];

            // 3 step -> moving the window
            i++;
            j++;
        }
    }
    return mx;
}

int main()
{
    int arr[] = {100, 200, 300, 400};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2; // represents size of window

    cout << "The maximum sum of the subarray of size " << k << " is: " << maxSumSubarrayOfSizeK(arr, n, k);

    return 0;
}