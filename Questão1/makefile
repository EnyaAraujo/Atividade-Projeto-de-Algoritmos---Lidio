CC = gcc
CFLAGS = -I./ncurses-local/include
LDFLAGS = -L./ncurses-local/lib -lncurses

SRC = src/main.c
OUT = programa

all:
	$(CC) $(SRC) $(CFLAGS) $(LDFLAGS) -o $(OUT)

run: all
	LD_LIBRARY_PATH=./ncurses-local/lib ./$(OUT)

clean:
	rm -f $(OUT)

