flighttimes: flighttimes.o readline.o
	gcc -o flighttimes flighttimes.o readline.o

flighttimes.o: flighttimes.c readline.h
	gcc -c flighttimes.c

readline.o: readline.c readline.h
	gcc -c readline.c