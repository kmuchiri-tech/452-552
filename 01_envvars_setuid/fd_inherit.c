#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

static int run_child(int fd, const char *label)
{
    pid_t child = fork();
    int status;

    if (child < 0) {
        perror("fork");
        return 1;
    }

    if (child == 0) {
        char fd_text[32];
        char *const argv[] = {"/bin/sh", "-c",
            "if [ -e /proc/self/fd/$LAB_FD ]; then "
            "echo \"$LAB_LABEL: descriptor inherited\"; "
            "else echo \"$LAB_LABEL: descriptor closed on exec\"; fi",
            NULL};
        char label_env[128];
        char fd_env[64];
        char *envp[] = {label_env, fd_env, "PATH=/usr/bin:/bin", NULL};

        snprintf(label_env, sizeof(label_env), "LAB_LABEL=%s", label);
        snprintf(fd_text, sizeof(fd_text), "%d", fd);
        snprintf(fd_env, sizeof(fd_env), "LAB_FD=%s", fd_text);
        execve(argv[0], argv, envp);
        perror("execve");
        _exit(1);
    }

    if (waitpid(child, &status, 0) < 0) {
        perror("waitpid");
        return 1;
    }
    return 0;
}

int main(void)
{
    int fd = open("/tmp/cybr442_fd_demo.txt",
                  O_WRONLY | O_CREAT | O_TRUNC, 0600);

    if (fd < 0) {
        perror("open");
        return 1;
    }

    dprintf(fd, "Controlled file-descriptor inheritance demonstration.\n");

    if (run_child(fd, "before FD_CLOEXEC") != 0) {
        close(fd);
        return 1;
    }

    if (fcntl(fd, F_SETFD, FD_CLOEXEC) < 0) {
        perror("fcntl");
        close(fd);
        return 1;
    }

    if (run_child(fd, "after FD_CLOEXEC") != 0) {
        close(fd);
        return 1;
    }

    close(fd);
    return 0;
}
