#include <stdio.h>
#include <stdbool.h>
#include <string.h>
 
/**
 * @brief Checks if a string (or a portion of it) is a palindrome.
 *
 * P-IN:  s is a valid null-terminated string (or NULL).
 *        first and last are valid indices within s (first <= last).
 * P-OUT: returns 1 if s[first..last] is a palindrome, 0 otherwise.
 */
bool isPalindrome(const char *s, int first, int last) {
        if(s == NULL) return false;
        while (first <last)
         {
             if( s[first] != s[last]){
                return false;
             }else{
                first++;
                last--;
             }
         }
         return true;
         
}
 
int main() {
    // Test cases
    const char *words[] = {"racecar", "hello", "madam", "abba", "a", ""};
    int n = sizeof(words) / sizeof(words[0]);
 
    for (int i = 0; i < n; i++) {
        int last = (int)strlen(words[i]) - 1;
        int result = isPalindrome(words[i], 0, last);
        printf("\"%s\" -> %s\n", words[i], result ? "Palindrome ✓" : "Not a palindrome ✗");
    }
 
    return 0;
}