# Lab Observation Worksheet

Name:

Course section:

Date:

## Part 1

1. What is the difference between a shell variable and an exported environment variable?
2. What changed after `export LAB_NOTE`?
3. What changed after `unset LAB_NOTE`?

## Part 2

1. Which values did the child inherit?
2. Did the child's change alter the parent?
3. What process-memory behavior explains the result?

## Part 3

1. Compare the `inherit` and `clean` modes.
2. Why is an explicit environment safer for a privileged process?
3. Which variables belong in a minimal allowlist?

## Part 4

1. Which `labdate` executable ran?
2. What security risk follows from searching an untrusted PATH?
3. Give two defensive controls.

## Part 5

1. Which function invokes a shell?
2. Why does shell interpretation increase attack surface?
3. When is direct execution preferable?

## Part 6

1. What resource did the child inherit?
2. What changed after `FD_CLOEXEC`?
3. Name two other resources a privileged process should close.

## Part 7

1. What happened with `LD_PRELOAD` during normal execution?
2. What happened during Set-UID execution?
3. What Linux security behavior explains the difference?

## Secure design review

List three secure coding rules for privilege-changing programs and connect each rule to evidence from this lab.
