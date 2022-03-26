CC=cc
INCLUDE_DIR=include
CFLAGS=-Wall -llowdown
DEPS=coredoc.h markdown.h
BIN=coredoc
OBJ=main.o coredoc.o markdown.o


.PHONY: clean

%.o: %.c $(DEPS)
	$(CC) -c $< -o $@ $(CFLAGS)
$(BIN): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm main.o coredoc.o coredoc markdown.o
