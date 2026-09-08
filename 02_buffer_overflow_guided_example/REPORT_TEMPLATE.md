# Guided Buffer Overflow Example Report

Name:

Date:

## 1. Environment check

Paste the output of `uname -m`, `gcc --version`, and `gdb --version`.

Explain whether your VM uses x86_64 or ARM64.

## 2. Normal input

Include a screenshot of the program processing a short input.

What evidence shows that the program returned normally?

## 3. Oversized input

Include a screenshot of the vulnerable program processing the generated input.

What changed? Explain why 80 bytes create a problem for a 24-byte buffer.

## 4. Debugger observation

Include a screenshot from GDB showing where the program stopped.

Describe what the debugger reveals. Do not write only "segmentation fault."

## 5. Protected build

Include a screenshot of the protected program processing the same oversized input.

Explain how StackGuard changes the result.

## 6. Connection to the SEED lab

Explain the relationship among the buffer, saved control data, return address, and program control flow.

## 7. Reflection

Name one coding practice and one compiler or operating-system defense that reduces buffer-overflow risk.
