all: virtualmem

virtualmem: virtualmem.o
	gcc virtualmem.o -o virtualmem

virtualmem.o: virtualmem.c
	gcc -c virtualmem.c 

clean :
	rm -rf *o virtualmem
