PROJECT:=webserver

CC:=gcc
CFLAGS:=-O2 -Wall -std=c99 -Iinclude
LDFLAGS:=$(CFLAGS)

SRC:=$(wildcard *.c)
OBJ:=$(SRC:%.c=%.o)

$(PROJECT): $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	
.PHONY: all
all: clean $(PROJECT)

.PHONY: clean
clean:
	rm -rf $(PROJECT) $(OBJ)
