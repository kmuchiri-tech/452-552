#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    const char *name;
    const char *value;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s VARIABLE_NAME\n", argv[0]);
        return 1;
    }

    name = argv[1];
    value = getenv(name);

    if (value == NULL) {
        printf("%s is not present in this process environment.\n", name);
        return 0;
    }

    printf("%s=%s\n", name, value);
    return 0;
}
