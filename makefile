AR=ar
CC=gcc 
FLAGS= -Wall -g
all: main.o stringProg

stringProg: main.o 
	$(CC) $(FLAGS) -o stringProg main.o 	

main.o: main.c
	$(CC) $(FLAGS) -c main.c

.PHONY: clean all
clean:
	rm -f *.a *.so *.o stringProg