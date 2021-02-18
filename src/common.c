#include <ctype.h>
#include <string.h>

#include "common.h"

int stralpha(const char *s)
{
    for (int i = 0; i < strlen(s); i++)
    {
        if (!isalpha(s[i]))
            return 0;
    }
    return 1;
}