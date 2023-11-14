/*Given a string you need to print the size of the longest possible substring that has exactly k unique characters.
Example:
Input:
2
aabacbebebe
3
aaaa
1
Output:
7
4
*/
#include <bits/stdc++.h>
using namespace std;

int longestSubstringWithKUniqueCharacters(string str, int n, int k)
{
    int i = 0;
    int j = 0;
    int ans = INT_MIN;
    unordered_map<char, int> mp;

    if (k > n)
    {
        return -1;
    }

    while (j < n)
    {
        mp[str[j]]++;
        if (mp.size() < k)
        {
            j++;
        }
        else if (mp.size() == k)
        {
            ans = max(ans, j - i + 1);
            j++;
        }
        else if (mp.size() > k)
        {
            while (mp.size() > k)
            {
                mp[str[i]]--;
                if (mp[str[i]] == 0)
                {
                    mp.erase(str[i]);
                }
                i++;
            }
            j++;
        }
    }
    return ans;
}

int main()
{
    string str = {"aabacbebebe"};
    int n = str.size();
    int k = 3;

    int ans = longestSubstringWithKUniqueCharacters(str, n, k);
    cout << "The length of longest substring with " << k << " unique characters is: " << ans;

    return 0;
}