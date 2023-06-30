FLAGS=-Wall -Wextra

all : main

main : main.o
	g++ $(FLAGS) -o main main.o

main.o : main.cpp
	g++ $(FLAGS) -c -o main.o main.cpp

run : all
	./main

output : all
	./main > output

clean :
	rm *.o main

dist : clean
	tar zcvf archive.tgz *

check :
	cppcheck --enable=all --suppress=missingIncludeSystem -I. .
	flawfinder .

.PHONY : run output clean dist check
