#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#include "common.h"

// Vigenere cipher
char *getfullkey(const char *key, const char *text) {
    size_t klen = strlen(key), tlen = strlen(text);

    char *fullkey = malloc(tlen + 1);
    for (int i = 0; i < tlen; i++)
    {
        fullkey[i] = key[i % klen];
    }
    fullkey[tlen] = '\0';
    return fullkey;
}

void encode(const char *key, char *text)
{
    ensurealpha(key, text);

    char *fullkey = getfullkey(key, text);
    for (int i = 0; i < strlen(text); i++)
    {
        char c_m = tolower(text[i]) - 97, c_k = tolower(key[i]) - 97;
        char c = (c_m + c_k) % 26;
        text[i] = c + 97;
    }
    free(fullkey);
}

void decode(const char *key, char *text)
{
    ensurealpha(key, text);

    char *fullkey = getfullkey(key, text);
    for (int i = 0; i < strlen(text); i++)
    {
        char c_m = tolower(text[i]) - 97, c_k = tolower(fullkey[i]) - 97;
        int8_t c = (c_m - c_k + 26) % 26;
        text[i] = c + 97;
    }
    free(fullkey);
}

