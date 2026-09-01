#define _GNU_SOURCE
#include <grp.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <unistd.h>

extern char **environ;

static void close_extra_descriptors(void)
{
    struct rlimit limit;
    rlim_t fd;

    if (getrlimit(RLIMIT_NOFILE, &limit) != 0) {
        return;
    }

    if (limit.rlim_cur == RLIM_INFINITY || limit.rlim_cur > 4096) {
        limit.rlim_cur = 4096;
    }

    for (fd = 3; fd < limit.rlim_cur; ++fd) {
        close((int)fd);
    }
}

int main(void)
{
    uid_t real_uid = getuid();
    gid_t real_gid = getgid();
    char *const argv[] = {"/usr/bin/id", NULL};
    char *const safe_env[] = {
        "PATH=/usr/bin:/bin",
        "LANG=C",
        "IFS= \t\n",
        NULL
    };

    if (clearenv() != 0) {
        perror("clearenv");
        return 1;
    }

    if (setgroups(0, NULL) != 0 && geteuid() == 0) {
        perror("setgroups");
        return 1;
    }

    if (setgid(real_gid) != 0 || setuid(real_uid) != 0) {
        perror("drop privileges");
        return 1;
    }

    close_extra_descriptors();
    execve(argv[0], argv, safe_env);
    perror("execve");
    return 1;
}
