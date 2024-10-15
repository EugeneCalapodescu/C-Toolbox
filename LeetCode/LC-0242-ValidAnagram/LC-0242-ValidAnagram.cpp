/* LC-0242-ValidAnagram

Given two strings s and t, return true if t is an
anagram
of s, and false otherwise.



Example 1:
    Input: s = "anagram", t = "nagaram"
    Output: true

Example 2:
    Input: s = "rat", t = "car"
    Output: false

*/

/*
  Nice solution from leetcode, one single loop, and an array

    bool isAnagram(string s, string t) {
        int n = s.length();
        int m = t.length();

        if (n != m) 
            return false;
        
        int str[26] = {0};
        
        for(int i = 0; i < n; i++) 
        {
            str[s[i] - 'a']++;
            str[t[i] - 'a']--;
        }
        
        for(int i = 0; i < 26; i++)
            if(str[i] != 0) 
                return false;

        return true;
*/

#include <iostream>
#include <map>
using namespace std;

bool isAnagram(string s, string t) 
{
    map<char, int> ms;
    for (int i = 0; i < s.size(); i++)
    {
        auto found = ms.find(s[i]);
        if (found == ms.end())
            ms[s[i]] = 1;
        else
            ms[s[i]] ++;
    }
    
    map<char, int> mt;
    for (int i = 0; i < t.size(); i++)
    {
        auto found = mt.find(t[i]);
        if (found == mt.end())
            mt[t[i]] = 1;
        else
            mt[t[i]] ++;
    }

    return ms == mt;

/*
    for (auto kv : ms)
    {
        auto found = mt.find(kv.first);
        if (found == mt.end())
            return false;
        if (kv.second != found->second)
            return false;
    }

    for (auto kv : mt)
    {
        auto found = ms.find(kv.first);
        if (found == ms.end())
            return false;
        if (kv.second != found->second)
            return false;
    }

    return true;
*/
}

int main()
{
    std::cout << isAnagram("car", "rac") << "\n";
}

