CC=gcc
CFLAGS=-Wall

executable: AirportManagement.o TSDDA.o TSEvr.o ch8_AVLpointer.o ch8_BSTpointerR.o Evretirio.o AirportManagementFuncts.o
	$(CC) $(CFLAGS) -g3 -o prog AirportManagement.o Evretirio.o TSDDA.o TSEvr.o ch8_AVLpointer.o ch8_BSTpointerR.o AirportManagementFuncts.o
AirportManagement.o: AirportManagement.c
	$(CC) $(CFLAGS) -c AirportManagement.c
AirportManagementFuncts.o: AirportManagementFuncts.c
	$(CC) $(CFLAGS) -c AirportManagementFuncts.c
Evretirio.o: Evretirio.c
	$(CC) $(CFLAGS) -c Evretirio.c
TSDDA.o: TSDDA.c
	$(CC) $(CFLAGS) -c TSDDA.c
TSEvr.o: TSEvr.c
	$(CC) $(CFLAGS) -c TSEvr.c
ch8_AVLpointer.o: AVL/ch8_AVLpointer.c
	$(CC) $(CFLAGS) -c AVL/ch8_AVLpointer.c
ch8_BSTpointerR.o: BST/ch8_BSTpointerR.c
	$(CC) $(CFLAGS) -c BST/ch8_BSTpointerR.c

.PHONY: clean

clean:
	rm -f prog AirportManagement.o Evretirio.o TSDDA.o TSEvr.o ch8_AVLpointer.o ch8_BSTpointerR.o AirportManagementFuncts.o
