# Lab 1: Environment Variables and Set-UID Programs

## Purpose

This lab examines how Linux processes receive environment variables and how privileged programs must treat external input. You will compare process environments, study `fork()` and `execve()`, observe PATH-based command resolution, test dynamic-loader behavior, and examine file-descriptor inheritance.

## Learning outcomes

After completing this lab, you should be able to:

1. Explain how shell variables differ from exported environment variables.
2. Compare the environments of parent and child processes.
3. Explain how `fork()`, `execve()`, and `system()` handle process state.
4. Describe why PATH, dynamic-loader variables, and inherited file descriptors matter to privileged programs.
5. Apply secure programming practices to programs that cross a privilege boundary.

## Required environment

Use the course Ubuntu virtual machine only.

- Ubuntu 22.04 or compatible Linux VM
- GCC and Make
- A standard user account with `sudo` access
- A VM snapshot created before the lab

Do not perform these exercises on a shared server, production computer, or personally important system.

## Setup

Open a terminal in this folder:

```bash
cd 01_envvars_setuid
make
```

Create a snapshot before changing ownership or permissions.

## Part 1: Shell and exported variables

Run:

```bash
LAB_NOTE="local-shell-value"
echo "$LAB_NOTE"
./env_print LAB_NOTE

export LAB_NOTE
./env_print LAB_NOTE

unset LAB_NOTE
./env_print LAB_NOTE
```

Record which commands see the variable and explain why.

## Part 2: Environment inheritance across fork

Run:

```bash
export LAB_COLOR=blue
./fork_env LAB_COLOR
```

Compare the parent and child output. Explain what the child inherits and whether a child-process change alters the parent.

## Part 3: Environment selection with execve

Run:

```bash
export LAB_TOKEN=from-shell
./exec_env inherit
./exec_env clean
```

The first mode passes the current environment. The second supplies a small, explicit environment. Explain the security advantage of an allowlist.

## Part 4: PATH and command selection

Create a harmless demonstration command:

```bash
mkdir -p demo-bin
printf '#!/bin/sh\necho "Demo command selected from custom PATH"\n' > demo-bin/labdate
chmod 755 demo-bin/labdate
```

Test both programs:

```bash
PATH="$PWD/demo-bin:/usr/bin:/bin" ./path_search
PATH="$PWD/demo-bin:/usr/bin:/bin" ./fixed_path
```

Explain why a privileged program should prefer an absolute executable path and a controlled environment.

## Part 5: system() and execve()

Run:

```bash
./launch_compare
```

Review the source code. Identify which call invokes a shell and which call directly starts a program.

## Part 6: File-descriptor inheritance

Run:

```bash
./fd_inherit
cat /tmp/cybr442_fd_demo.txt
```

The parent opens a file and then starts a child process. Review where `FD_CLOEXEC` is applied. Explain how close-on-exec limits unintended resource inheritance.

## Part 7: Dynamic-loader variables

Run as your normal user:

```bash
make loader-demo
LD_PRELOAD="$PWD/liblabmessage.so" ./loader_target
```

Then create a controlled Set-UID copy inside the VM:

```bash
sudo cp loader_target /usr/local/bin/cybr442-loader-target
sudo chown root:root /usr/local/bin/cybr442-loader-target
sudo chmod 4755 /usr/local/bin/cybr442-loader-target
LD_PRELOAD="$PWD/liblabmessage.so" /usr/local/bin/cybr442-loader-target
```

Compare the results. Modern Linux loaders enter a secure-execution mode for privilege-changing programs and restrict unsafe loader variables.

Remove the test program immediately:

```bash
sudo rm -f /usr/local/bin/cybr442-loader-target
```

## Part 8: Secure design review

Inspect `secure_template.c`. Identify each defensive choice:

- controlled PATH
- cleared environment
- absolute executable path
- dropped supplementary groups
- permanent privilege drop
- closed nonessential file descriptors

Compile and run:

```bash
make secure_template
./secure_template
```

## Submission

Submit one PDF containing:

1. Your name and course section.
2. Screenshots of Parts 1 through 7.
3. Answers from `OBSERVATIONS.md`.
4. A short reflection naming three rules for privileged programs.
5. Evidence showing removal of the Set-UID test file.

## Cleanup

Run:

```bash
make clean
rm -rf demo-bin
sudo rm -f /usr/local/bin/cybr442-loader-target
unset LAB_NOTE LAB_COLOR LAB_TOKEN LD_PRELOAD
```

## Authorship note

This teaching package was independently written for CYBR 442/552 by Dr. Kevin Muchiri. The lab addresses standard operating-system security concepts commonly taught through environment-variable and Set-UID experiments. No source files from the referenced repository were copied verbatim.
