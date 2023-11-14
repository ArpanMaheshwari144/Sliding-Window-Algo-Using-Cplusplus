/*Given a string s, find the length of the longest substring without repeating characters.
Example:
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring
*/
#include <bits/stdc++.h>
using namespace std;

int longestSubstringWithoutRepeatingCharacters(string str, int n)
{
    int i = 0;
    int j = 0;
    int ans = INT_MIN;
    unordered_map<char, int> mp;

    while (j < n)
    {
        mp[str[j]]++;

        // j-i+1 represents the size of the window
        if (mp.size() > j - i + 1)
        {
            j++;
        }
        else if (mp.size() == j - i + 1)
        {
            ans = max(ans, j - i + 1);
            j++;
        }
        else if (mp.size() < j - i + 1)
        {
            while (mp.size() < j - i + 1)
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
    string str = {"pwwkew"};
    int n = str.size();

    cout << "The length of the longest substring without repeating characters is: " << longestSubstringWithoutRepeatingCharacters(str, n);

    return 0;
}