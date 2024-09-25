

// 2.)REVERSE WORDS
// Given a String str, reverse the string without reversing its individual words. Words are separated by dots.
// Note: The last cha

// C++

#include <bits/stdc++.h>
using namespace std;

// Function to reverse a sequence from "begin"
// index to "end" index
void reverse(string &s, int begin, int end)
{
    while (begin < end)
    {
        swap(s[begin++], s[end--]);
    }
}

// Function to reverse individual words in a string
void reverseWords(string &s)
{
    int word_begin = -1;

    // STEP 1. Reverse each word in the string
    for (int i = 0; i < s.size(); i++)
    {

        // Beginning of a word
        if (word_begin == -1 && s[i] != ' ')
        {
            word_begin = i;
        }

        // End of a word
        if (word_begin != -1 && (s[i + 1] == ' ' || i + 1 == s.size()))
        {
            reverse(s, word_begin, i);
            word_begin = -1;
        }
    }

    /*STEP 2 of the above algorithm */
    reverse(s, 0, s.size() - 1);
}

// Driver Code
int main()
{

    string s = "  geeks for all";
    reverseWords(s);
    cout << s;
    return 0;
}







