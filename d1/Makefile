flag = -Wall -Wextra

main : main.o
	gcc $(flag) -I. -o main main.o

main.o : main.c
	gcc $(flag) -I. -c main.c -o main.o

clean :
	rm -f *.o main

run : main
	./main

.PHONY : run clean
