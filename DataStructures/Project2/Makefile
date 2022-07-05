CC=gcc
CFLAGS=-Wall

executable: Session.o main.o print_opts.o
	$(CC) $(CFLAGS) -o prog main.o Session.o print_opts.o
Session.o: Session.c
	$(CC) $(CFLAGS) -c Session.c
main.o: main.c
	$(CC) $(CFLAGS) -c main.c
print_opts.o: print_opts.c
	$(CC) $(CFLAGS) -c print_opts.c
.PHONY: clean

clean:
	rm -f prog main.o Session.o print_opts.o
