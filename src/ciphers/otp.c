#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#include "common.h"

// Shift cipher

void encode(const char *key, char *text)
{
    ensurealpha(key, text);

    assert(strlen(key) == strlen(text), "The key must be equal length to text!");

    for (int i = 0; i < strlen(text); i++)
    {
        char c_m = tolower(text[i]) - 97, c_k = tolower(key[i]) - 97;
        char c = (c_m + c_k) % 26;
        text[i] = c + 97;
    }
}

void decode(const char *key, char *text)
{
    ensurealpha(key, text);
    
    assert(strlen(key) == strlen(text), "The key must be equal length to text!");

    for (int i = 0; i < strlen(text); i++)
    {
        char c_m = tolower(text[i]) - 97,  c_k = tolower(key[i]) - 97;
        int8_t c = (c_m - c_k + 26) % 26;
        text[i] = c + 97;
    }
}
