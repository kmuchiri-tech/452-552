# Buffer Overflow Lab Troubleshooting

## First rule

Confirm that every command runs inside the Linux VM.

```bash
uname -a
pwd
whoami
```

## `gcc: command not found`

```bash
sudo apt update
sudo apt install -y build-essential
```

## `gdb: command not found`

```bash
sudo apt update
sudo apt install -y gdb
```

## `unzip: command not found`

```bash
sudo apt install -y unzip
```

## `No such file or directory`

Check your location:

```bash
pwd
ls -la
```

Search for the package:

```bash
find ~ -name "Labsetup.zip" 2>/dev/null
find ~ -type d -name "Labsetup" 2>/dev/null
```

## Permission denied when running a script

```bash
chmod +x make_input.py
python3 make_input.py
```

For the SEED skeleton:

```bash
chmod +x exploit.py
python3 exploit.py
```

## The shared folder creates permission problems

The official SEED instructions warn against unzipping Labsetup in a shared folder.

Move the ZIP into the VM:

```bash
mkdir -p ~/labs/buffer-overflow
cp /path/to/shared/folder/Labsetup.zip ~/labs/buffer-overflow/
cd ~/labs/buffer-overflow
unzip Labsetup.zip
```

## The vulnerable program does not crash

Results vary by compiler, architecture, and memory layout.

Confirm that you built the guided vulnerable version:

```bash
make clean
make vulnerable
file vulnerable
```

Generate and verify the input:

```bash
python3 make_input.py
wc -c crash_input.txt
./vulnerable "$(cat crash_input.txt)"
echo $?
```

Record the observed behavior. A crash is one possible result, not the sole proof of an overflow.

## The protected version does not show the expected message

Rebuild:

```bash
make clean
make protected
./protected "$(cat crash_input.txt)"
```

Messages differ across systems. Look for abnormal termination or a message containing `stack`, `smashing`, or `overflow`.

## GDB exits or shows different addresses

Memory addresses differ across machines and executions. Use your own results.

Start again:

```bash
gdb ./vulnerable
```

Then:

```text
break copy_message
run AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
next
info frame
info registers
backtrace
```

## ARM64 Docker does not start

Confirm Docker:

```bash
docker --version
docker compose version
```

Inside the ARM64 `Labsetup` directory:

```bash
cd server-code
make
make install
cd ..
docker compose build
docker compose up
```

Keep the terminal open while the containers run. Open a second terminal for client commands.

## `dcbuild`, `dcup`, or `dockps` is not found

Those names are aliases supplied by some SEED VM configurations. Use the full commands:

```bash
docker compose build
docker compose up
docker ps
```

## Before contacting the professor

Send:

1. Your processor type
2. Your VM software
3. Output from `uname -m`
4. The command entered
5. The complete error message
6. A screenshot showing the terminal and current folder

This information supports faster diagnosis.
