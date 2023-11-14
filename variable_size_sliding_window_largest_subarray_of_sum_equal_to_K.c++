/*Given an array containing N positive integers and an integer K. Your task is to find the length of the longest Sub-Array with sum of the elements equal to the given value K.
For Input:
1
7 5
4 1 1 1 2 3 5
Output is: 
4
*/
#include <bits/stdc++.h>
using namespace std;

int largestSubarrayOfSumEqualToK(int arr[], int n, int k)
{
    int i = 0;
    int j = 0;
    int mx = 0;
    long long int sum = 0;

    while (j < n)
    {
        sum = sum + arr[j];
        if (sum < k)
        {
            j++;
        }
        else if (sum == k)
        {
            // mx = max(mx, j - i + 1);
            // j++;

            // OR

            if (j - i + 1 > mx)
            {
                mx = j - i + 1; // j - i + 1 -> stores the size of all windows in array
                j++;
            }
        }
        else if (sum > k)
        {
            while (sum > k)
            {
                sum = sum - arr[i];
                i++;
            }
            j++;
        }
    }
    return mx;
}

int main()
{
    /*Given an array containing N positive integers and an integer K. Your task is to find the length of the longest Sub-Array with sum of the elements equal to the given value K.*/
    int arr[] = {4, 1, 1, 1, 2, 3, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 5; // represents the sum

    cout << "The size of the largest subarray having sum " << k << " is: " << largestSubarrayOfSumEqualToK(arr, n, k);

    return 0;
}