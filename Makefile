CC = gcc
CFLAGS = -Wall -std=c99

compareCPU: main.c
	$(CC) $(CFLAGS) main.c -o compareCPU

clean:
	rm -f compareCPU