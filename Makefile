CC=gcc
CFLAGS=-Wall -Wextra -Werror

all:
	$(CC) $(CFLAGS) main.c encode_decode.h encode_decode.c -o a -lm

