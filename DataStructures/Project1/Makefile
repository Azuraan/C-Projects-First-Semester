CC=gcc
CFLAGS=-Wall

executable: ch6_QArray.o ch6_Simulation.o controller.o TStoixeiouOuras.o
	$(CC) $(CFLAGS) -o prog ch6_QArray.o ch6_Simulation.o controller.o TStoixeiouOuras.o
ch6_QArray.o: ch6_QArray.c
	$(CC) $(CFLAGS) -c ch6_QArray.c
ch6_Simulation.o: ch6_Simulation.c
	$(CC) $(CFLAGS) -c ch6_Simulation.c
TStoixeiouOuras.o: TStoixeiouOuras.c
	$(CC) $(CFLAGS) -c TStoixeiouOuras.c
controller.o: controller.c
	$(CC) $(CFLAGS) -c controller.c
.PHONY: clean

clean:
	rm -f prog ch6_QArray.o ch6_Simulation.o controller.o TStoixeiouOuras.o

