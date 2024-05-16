items: items.o readline.o
	gcc -o items items.o readline.o

items.o: items.c readline.h
	gcc -c items.c

readline.o: readline.c readline.h
	gcc -c readline.c