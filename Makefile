CC=gcc
CFLAGS=-Wall -Wextra

SRC=src/karsh.c src/explain.c src/scheduler.c

all:
	$(CC) $(CFLAGS) $(SRC) -o karsh

clean:
	rm -f karsh
