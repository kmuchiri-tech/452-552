# CYBR 452/552 Computer and Network Security Labs

Hands-on laboratory materials for CYBR 452 and CYBR 552.

## Start Here

New to the virtual-machine environment?

[Open the VirtualBox Shared Folder Setup](virtualbox_shared_folder_setup/README.md)

The setup package includes Windows and Ubuntu preparation, verification steps, annotated references, and troubleshooting guidance.

## Lab One: Environment Variables and Set-UID

[Open Lab One](01_envvars_setuid/README.md)

Complete all Set-UID work inside the designated Ubuntu virtual machine.

## Lab Two: Buffer Overflow

### Begin with the guided example

[Open the Guided Buffer Overflow Example](02_buffer_overflow_guided_example/README.md)

This example helps you understand:

- Fixed-size buffers
- Unchecked copying
- Stack corruption
- GDB observations
- StackGuard protection
- Lab-report documentation

The example does not provide the graded SEED exploit or assignment-specific payload values.

### Continue to the assigned SEED lab

Choose by processor architecture:

- [Intel/AMD Set-UID Version](https://seedsecuritylabs.org/Labs_20.04/Software/Buffer_Overflow_Setuid/) for Windows, most Linux systems, and Intel Macs
- [Apple Silicon ARM64 Server Version](https://seedsecuritylabs.org/Labs_20.04/Software/Buffer_Overflow_Server_ARM64/) for M-series Macs

Do not mix instructions from the two versions. Their architectures, setup methods, register names, and attack environments differ.

## Student workflow

1. Confirm your processor architecture.
2. Start the Linux VM.
3. Complete the guided example.
4. Download the correct SEED Labsetup package inside the VM.
5. Complete the assigned SEED tasks.
6. Capture evidence while working.
7. Explain why each result occurred.
8. Submit the report through Brightspace.

## Academic Use

Use these materials only inside the designated course VM or another authorized environment. Follow university policy, course rules, and applicable law.

## Author

Dr. Kevin Muchiri
