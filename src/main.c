#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#include "common.h"

int main(int argc, const char **argv)
{
    if (argc != 4)
    {
        printf("Usage: %s <encode|decode> <key> <text>\n", argv[0]);
        return -1;
    };

    const char *function = argv[1];
    const char *key = argv[2];

    char *text = strdup(argv[3]);

    log("key = %s, text = %s", key, text);

    if (!strcmp(function, "encode"))
    {
        encode(key, text);
        if(isatty(fileno(stdout)))
            printf("ciphertext = %s\n", text);
        else
            printf("%s", text);
    }
    else if (!strcmp(function, "decode"))
    {
        decode(key, text);
        if(isatty(fileno(stdout)))
            printf("plaintext = %s\n", text);
        else
            printf("%s", text);
    }
    return 0;
};
