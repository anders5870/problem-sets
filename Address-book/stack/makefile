driver: driver.o stack.o
	gcc -o driver driver.o stack.o
driver.o: driver.c stack.h
	gcc -c -g driver.c
stack.o: stack.c stack.h
	gcc -c -g stack.c
