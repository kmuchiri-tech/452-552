CC = gcc
CFLAGS = -Wall -Wextra -g

.PHONY: all clean

all: vulnerable protected

vulnerable: overflow_demo.c
	$(CC) $(CFLAGS) -fno-stack-protector -no-pie -o vulnerable overflow_demo.c

protected: overflow_demo.c
	$(CC) $(CFLAGS) -fstack-protector-all -D_FORTIFY_SOURCE=2 -O2 -o protected overflow_demo.c

clean:
	rm -f vulnerable protected crash_input.txt
