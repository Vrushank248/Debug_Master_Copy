// 1.)	VALID ANAGRAM
// Given two strings s1 and s2 consisting of lowercase characters, the task is to check whether the two given strings are anagrams of each other or not. An anagram of a string is another string that contains the same characters, only the order of characters can be different. For example, “act” and “tac” are anagrams of each other.

// Code:

// C++:

#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string s1, string s2)
{

    // If the lengths are not the same, they cannot be
    // anagrams
    if (s1.length() != s2.length())
    {
        return false;
    }

    // Initialize s1 frequency array for 26 lowercase
    // characters
    vector<int> freq(26, 0);

    // Count frequency of each character in string s1
    for (char c : s1)
    {
        freq[c - 'a']++;
    }

    // Subtract frequency of each character in string s2
    for (char c : s2)
    {
        freq[c - 'a']--;
    }

    // Check if all frequencies are zero
    for (int count : freq)
    {
        if (count != 0)
        {
            return false;
        }
    }

    return true;
}

// Driver code
int main()
{
    string s1 = "listen";
    string s2 = "silent";
    cout << boolalpha << isAnagram(s1, s2) << endl;

    s1 = "hello";
    s2 = "bello";
    cout << boolalpha << isAnagram(s1, s2) << endl;

    return 0;
}
