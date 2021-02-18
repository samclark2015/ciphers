#pragma once

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define DEBUG 1

#define assert(cond, msg)                         \
    {                                             \
        if (!(cond))                              \
        {                                         \
            fprintf(stderr, "Assertion error: %s\n", msg); \
            exit(-1);                             \
        }                                         \
    }

#if DEBUG
#define log(message, args...) fprintf(stderr, message "\n", args);
#else
#define log(message, args...)
#endif

#define ensurealpha(key, text)                          \
    assert(stralpha(key), "Key must be alphabetical!"); \
    assert(stralpha(text), "Text must be alphabetical!");

void encode(const char *key, char *text);
void decode(const char *key, char *text);

int stralpha(const char *);