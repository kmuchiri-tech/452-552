#include <stdio.h>
#include <string.h>

void copy_message(const char *input)
{
    char buffer[24];
    strcpy(buffer, input);
    printf("Stored message: %s\n", buffer);
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <message>\n", argv[0]);
        return 1;
    }

    printf("Input length: %zu bytes\n", strlen(argv[1]));
    copy_message(argv[1]);
    printf("Program returned normally.\n");
    return 0;
}
