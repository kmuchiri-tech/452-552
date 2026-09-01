CC := gcc
CFLAGS := -Wall -Wextra -Wpedantic -O0 -g
PROGRAMS := env_print fork_env exec_env path_search fixed_path launch_compare fd_inherit loader_target secure_template

.PHONY: all clean loader-demo

all: $(PROGRAMS)

env_print: env_print.c
	$(CC) $(CFLAGS) -o $@ $<

fork_env: fork_env.c
	$(CC) $(CFLAGS) -o $@ $<

exec_env: exec_env.c
	$(CC) $(CFLAGS) -o $@ $<

path_search: path_search.c
	$(CC) $(CFLAGS) -o $@ $<

fixed_path: fixed_path.c
	$(CC) $(CFLAGS) -o $@ $<

launch_compare: launch_compare.c
	$(CC) $(CFLAGS) -o $@ $<

fd_inherit: fd_inherit.c
	$(CC) $(CFLAGS) -o $@ $<

loader_target: loader_target.c
	$(CC) $(CFLAGS) -o $@ $<

liblabmessage.so: labmessage.c
	$(CC) $(CFLAGS) -fPIC -shared -o $@ $<

loader-demo: loader_target liblabmessage.so

secure_template: secure_template.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(PROGRAMS) liblabmessage.so
