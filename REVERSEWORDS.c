// 2.)REVERSE WORDS
// Given a String str, reverse the string without reversing its individual words. Words are separated by dots.
// Note: The last cha

#include <stdio.h>
#include <string.h>

// Function to reverse a sequence from "begin" index to "end" index
void reverse(char *s, int begin, int end) {
    while (begin < end) {
        char temp = s[begin];
        s[begin] = s[end];
        s[end] = temp;
        begin++;
        end--;
    }
}

// Function to reverse individual words in a string
void reverseWords(char *s) {
    int word_begin = -1;
    int len = strlen(s);

    // STEP 1: Reverse each word in the string
    for (int i = 0; i < len; i++) {

        // Beginning of a word
        if (word_begin == -1 && s[i] != ' ') {
            word_begin = i;
        }

        // End of a word
        if (word_begin != -1 && (s[i + 1] == ' ' || i + 1 == len)) {
            reverse(s, word_begin, i);
            word_begin = -1;
        }
    }

    // STEP 2: Reverse the entire string
    reverse(s, 0, len - 1);
}

// Driver Code
int main() {
    char s[] = "  geeks for all";
    reverseWords(s);
    printf("%s", s);
    return 0;
}
