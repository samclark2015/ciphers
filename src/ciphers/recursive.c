#include <string.h>

#include "common.h"
#include "b64.h"

#define KEYLEN 64
#define MAXBYTE 255

typedef unsigned char byte;

void encode(const char *key, char *text)
{
    assert(strlen(key) == 1, "Key must be 1 byte");
    size_t initlen = strlen(text);

    byte k = key[0];
    int keylen = strlen(key);

    for (int i = 0; i < initlen; i++)
    {
        byte p = text[i];
        byte c = (p + k) % MAXBYTE;
        log("p = %d, k = %d, c = %d", p, k, c);
        text[i] = c;
        k = p;
    }
}

void decode(const char *key, char *text)
{
    assert(strlen(key) == 1, "Key must be 1 byte");

    byte k = key[0];
    int keylen = strlen(key);

    for (int i = 0; i < strlen(text); i++)
    {
        byte c = text[i];
        byte p = (c - k + MAXBYTE) % MAXBYTE;
        log("c = %d, k = %d, p = %d", c, k, p);
        text[i] = p;
        k = p;
    }
}