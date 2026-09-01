#include <stdio.h>
#include <string.h>
#include <unistd.h>

extern char **environ;

int main(int argc, char *argv[])
{
    char *const program[] = {"/usr/bin/env", NULL};
    char *const clean_env[] = {
        "PATH=/usr/bin:/bin",
        "LANG=C",
        "LAB_TOKEN=from-explicit-list",
        NULL
    };
    char *const *selected_env;

    if (argc != 2 ||
        (strcmp(argv[1], "inherit") != 0 && strcmp(argv[1], "clean") != 0)) {
        fprintf(stderr, "Usage: %s inherit|clean\n", argv[0]);
        return 1;
    }

    selected_env = strcmp(argv[1], "inherit") == 0
        ? (char *const *)environ
        : clean_env;

    execve(program[0], program, selected_env);
    perror("execve");
    return 1;
}
