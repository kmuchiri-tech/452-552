#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

static void show_value(const char *who, const char *name)
{
    const char *value = getenv(name);
    printf("%s (pid=%ld): %s=%s\n", who, (long)getpid(), name,
           value == NULL ? "<unset>" : value);
}

int main(int argc, char *argv[])
{
    pid_t child;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s VARIABLE_NAME\n", argv[0]);
        return 1;
    }

    show_value("parent before fork", argv[1]);
    child = fork();

    if (child < 0) {
        perror("fork");
        return 1;
    }

    if (child == 0) {
        show_value("child inherited", argv[1]);
        if (setenv(argv[1], "changed-in-child", 1) != 0) {
            perror("setenv");
            return 1;
        }
        show_value("child after change", argv[1]);
        return 0;
    }

    if (waitpid(child, NULL, 0) < 0) {
        perror("waitpid");
        return 1;
    }

    show_value("parent after child exits", argv[1]);
    return 0;
}
