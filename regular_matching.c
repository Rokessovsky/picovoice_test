#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>

bool isMatch(char *text, char *pattern)
{
    if (*pattern == '\0')
        return *text == '\0';
    bool first_match = (*text != '\0' &&
                        (*pattern == *text || *pattern == '.'));

    if (*(pattern + 1) == '+')
    {
        if (!first_match)
            return false;
        char curr_char = *pattern;
        while (*text != '\0' && (*text == curr_char || curr_char == '.'))
        {
            if (isMatch(text + 1, pattern + 2))
                return true;
            text++;
        }
        return isMatch(text, pattern + 2);
    }
    else
    {
        return first_match && isMatch(text + 1, pattern + 1);
    }
}

int main()
{
    // Test cases
    assert(isMatch("", "") == true);
    assert(isMatch("a", "") == false);
    assert(isMatch("", "a") == false);
    assert(isMatch("a", "a") == true);
    assert(isMatch("a", "b") == false);
    assert(isMatch("aa", "a") == false);
    assert(isMatch("a", "a+") == true);
    assert(isMatch("aa", "a+") == true);
    assert(isMatch("aaa", "a+") == true);
    assert(isMatch("ab", "a+b") == true);
    assert(isMatch("b", "a+b") == false);
    assert(isMatch("aaab", "a+b") == true);
    assert(isMatch("ab", "a+b+") == true);
    assert(isMatch("abb", "a+b+") == true);
    assert(isMatch("aaabbb", "a+b+") == true);
    assert(isMatch("abc", "a+b+") == false);
    assert(isMatch("abbbcddddeeeefffff", "a+.b+.c+.d+.e+.f+.") == true);
    assert(isMatch("abcdabcd", "+.b+c+.d+.e+.f+.g") == false);
    assert(isMatch("abdjsdcmkde", ".+") == true);

    printf("All tests passed\n");
    return 0;
}