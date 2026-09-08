# Student Start Here: Buffer Overflow Lab

Use this guide before beginning the graded SEED assignment.

## Your learning sequence

### Stage 1: Identify your route

Run inside the Linux VM:

```bash
uname -m
```

| Result | Route |
| --- | --- |
| `x86_64`, `i686`, or `i386` | Intel/AMD Set-UID version |
| `aarch64` or `arm64` | Apple Silicon ARM64 Server version |

Do not combine commands from both routes.

### Stage 2: Confirm your tools

```bash
pwd
gcc --version
gdb --version
python3 --version
```

ARM64 students also run:

```bash
docker --version
docker compose version
```

If a required command fails, stop and use [Troubleshooting](TROUBLESHOOTING.md).

### Stage 3: Complete the guided example

Follow [README.md](README.md) from top to bottom.

You should finish with four pieces of evidence:

1. Normal input returns successfully.
2. Oversized input changes or crashes the vulnerable program.
3. GDB shows where execution stops.
4. The protected build detects the overwrite.

### Stage 4: Explain the concepts aloud

Before the graded lab, explain these statements to a partner:

- A buffer reserves a fixed amount of memory.
- An unchecked copy writes beyond the buffer boundary.
- Adjacent stack data includes control information.
- A changed return address changes program control flow.
- StackGuard detects corruption before a damaged return occurs.

If an explanation feels unclear, repeat the guided example before proceeding.

### Stage 5: Download the correct SEED package

Use the browser inside your VM.

- [Intel/AMD Set-UID Lab](https://seedsecuritylabs.org/Labs_20.04/Software/Buffer_Overflow_Setuid/)
- [Apple Silicon ARM64 Lab](https://seedsecuritylabs.org/Labs_20.04/Software/Buffer_Overflow_Server_ARM64/)

Download `Labsetup.zip`.

Move the ZIP to a regular folder inside the VM. Do not unzip the package in a VirtualBox shared folder.

Suggested location:

```bash
mkdir -p ~/labs/buffer-overflow
cp ~/Downloads/Labsetup.zip ~/labs/buffer-overflow/
cd ~/labs/buffer-overflow
unzip Labsetup.zip
cd Labsetup
ls
```

### Stage 6: Take evidence while working

For every required task, capture:

- The command
- Relevant output
- A screenshot
- What happened
- Why the result matters

Do not wait until the end to reconstruct the report.

## What mastery looks like

You are ready to submit when you independently explain:

1. Where the vulnerable buffer appears.
2. Why the input crosses its boundary.
3. How the offset relates to stored control data.
4. Why byte order and address length matter.
5. What the NOP sled does.
6. Why the chosen return address points into the payload.
7. How each tested countermeasure changes the result.
8. Why outputs differ between x86 and ARM64.

## Report quality check

Use [REPORT_TEMPLATE.md](REPORT_TEMPLATE.md) for the guided example. Follow the official SEED task order for the graded report.

A strong graded report contains:

- Task headings matching the assigned instructions
- Original screenshots
- Commands and meaningful output
- Explanations of chosen values
- Interpretation of failed attempts
- Countermeasure analysis
- A short concluding reflection

A screenshot alone proves activity. Your explanation proves learning.
