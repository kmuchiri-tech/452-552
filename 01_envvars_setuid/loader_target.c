#include <stdio.h>
#include <unistd.h>

int main(void)
{
    printf("loader target: real uid=%ld, effective uid=%ld\n",
           (long)getuid(), (long)geteuid());
    return 0;
}
