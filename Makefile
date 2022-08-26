FILES = main.c singly_linked_list.c
CC = gcc
CFLAGS = -g
main: $(FILES)
	$(CC) $(FILES) $(CFLAGS) -o main
