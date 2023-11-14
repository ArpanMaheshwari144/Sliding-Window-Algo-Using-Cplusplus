/*Given a word pat and a text txt. Return the count of the occurences of anagrams of the word in the text.
Example 1:
Input:
txt = forxxorfxdofr
pat = for
Output: 3
Explanation: for, orf and ofr appears in the txt, hence answer is 3.
Example 2:
Input:
txt = aabaabaa
pat = aaba
Output: 4
Explanation: aaba is present 4 timesin txt.
*/
#include <bits/stdc++.h>
using namespace std;

int countOccurrenceOfAnagram(string str, string ptr)
{
    int n = str.size();
    int m = ptr.size();
    int k = ptr.size();

    unordered_map<char, int> mp;
    for (int i = 0; i < m; i++)
    {
        mp[ptr[i]]++;
    }
    int i = 0;
    int j = 0;
    int count = mp.size();
    int ans = 0;

    while (j < n)
    {
        // syntax for checking whether a key is present or not
        /*if (m.find(key) == m.end())
            return "Not Present";
        return "Present";*/

        // this is for checking whether a character is present in the map or not
        if (mp.find(str[j]) != mp.end())
        {
            // if present so decrement the count
            mp[str[j]]--;
            if (mp[str[j]] == 0)
            {
                count--;
            }
        }
        if (j - i + 1 < k)
        {
            j++;
        }
        else if (j - i + 1 == k)
        {
            if (count == 0)
            {
                ans++;
            }
            if (mp.find(str[i]) != mp.end())
            {
                mp[str[i]]++;
                if (mp[str[j]] == 1)
                {
                    count++;
                }
                i++;
                j++;
            }
        }
    }
    return ans;
}

int main()
{
    string str = {"aabaabaa"};
    string ptr = {"aaba"};

    cout << countOccurrenceOfAnagram(str, ptr);

    return 0;
}