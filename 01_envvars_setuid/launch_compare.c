#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void)
{
    pid_t child;
    int status;

    puts("1. system() starts a shell to interpret a command string.");
    status = system("printf 'system child: '; /usr/bin/id -u");
    if (status == -1) {
        perror("system");
        return 1;
    }

    puts("2. execve() directly replaces a child process.");
    child = fork();
    if (child < 0) {
        perror("fork");
        return 1;
    }

    if (child == 0) {
        char *const argv[] = {"/usr/bin/id", "-u", NULL};
        char *const envp[] = {"PATH=/usr/bin:/bin", "LANG=C", NULL};
        execve(argv[0], argv, envp);
        perror("execve");
        _exit(1);
    }

    if (waitpid(child, &status, 0) < 0) {
        perror("waitpid");
        return 1;
    }

    return WIFEXITED(status) ? WEXITSTATUS(status) : 1;
}
