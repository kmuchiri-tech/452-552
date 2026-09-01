#include <stdio.h>
#include <unistd.h>

int main(void)
{
    char *const argv[] = {"/bin/date", NULL};
    char *const envp[] = {"PATH=/usr/bin:/bin", "LANG=C", NULL};

    puts("Calling /bin/date directly...");
    execve(argv[0], argv, envp);
    perror("execve");
    return 1;
}
