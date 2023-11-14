/*Given two strings s and t, return the minimum window in s which will contain all the characters in t. If there is no such window in s that covers all characters in t, return the empty string "".
Note that If there is such a window, it is guaranteed that there will always be only one unique minimum window in s.
Example 1:
Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Example 2:
Input: s = "a", t = "a"
Output: "a"
*/
#include <bits/stdc++.h>
using namespace std;

void minimumWindowSubstring(string s, string t)
{
    string res;
    int res_size = INT_MAX;
    unordered_map<char, int> mp;
    for (auto it : t)
    {
        mp[it]++;
    }
    int count = mp.size();
    int i = 0, j = 0;
    while (j < s.size())
    {
        mp[s[j]]--;
        if (mp[s[j]] == 0)
        {
            count--;
        }
        if (count > 0)
        {
            j++;
            continue;
        }
        while (count < 1)
        {
            if (res_size > j - i + 1)
            {
                res = s.substr(i, j - i + 1); // substring i se start hogi or j-i+1 tak jayegi
                res_size = res.size();
            }
            mp[s[i]]++;
            if (mp[s[i]] == 1)
            {
                count++;
            }
            i++;
        }
        j++;
    }
    cout << "The length of minimum substring is: " << res_size << endl;
    cout << "The string is: " << res;
}

int main()
{
    string s = "ADOBECODEBANC";
    string t = "ABC";

    minimumWindowSubstring(s, t);

    return 0;
}