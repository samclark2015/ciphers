#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#include "common.h"

// Affine cipher

int modMulInv(int i, int mod)
{
    for (int j = 0; j < mod; j++)
    {
        if ((i * j) % mod == 1)
        {
            return j;
        }
    }
    assert(0, "No modular multiplicative inverse found.");
}

void encode(const char *key, char *text)
{
    ensurealpha(key, text);

    assert(strlen(key) == 2, "The key must be two characters!");

    char a = tolower(key[0]) - 97;
    char b = tolower(key[1]) - 97;

    for (int i = 0; i < strlen(text); i++)
    {
        char c_m = tolower(text[i]) - 97;
        char c = (a * c_m + b) % 26;
        text[i] = c + 97;
    }
}

void decode(const char *key, char *text)
{
    ensurealpha(key, text);
    
    assert(strlen(key) == 2, "The key must be two characters!");

    char a1 = modMulInv(tolower(key[0]) - 97, 26);
    char b = tolower(key[1]) - 97;

    log("a' = %d, b = %d", a1, b);

    for (int i = 0; i < strlen(text); i++)
    {
        char c_m = tolower(text[i]) - 97;
        int8_t c = (a1 * (c_m - b)) % 26;
        text[i] = c + 97;
    }
}
