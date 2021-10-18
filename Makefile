OBJECTS = Main.o PDA.o Symbol.o
CFLAGS = -c -O3 -std=c++17 -I../include
SRC = src/Main.cc src/PDA.cc src/Symbol.cc

exe: $(OBJECTS)
	g++ $(SRC) -o exe
	mv *.o ./obj
	
Main.o:
	g++ $(CFLAGS) ./src/Main.cc

PDA.o:
	g++ $(CFLAGS) ./src/PDA.cc

Symbol.o:
	g++ $(CFLAGS) ./src/Symbol.cc

.PHONY: 

default:
	make exe

clean:
	rm -rf ./obj/*.o

run:
	make -s && ./exe input/APf.txt