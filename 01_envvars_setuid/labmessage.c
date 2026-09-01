#include <stdio.h>

__attribute__((constructor))
static void announce_library(void)
{
    fputs("liblabmessage.so loaded before main()\n", stderr);
}
