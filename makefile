OBJECTS = main.o
CFLAGS = -c -O3 -std=c++17 -I../include
SRC = src/main.cc

exe: $(OBJECTS)
	g++ $(SRC) -o exe
	mv *.o ./obj
	
main.o:
	g++ $(CFLAGS) ./src/main.cc

.PHONY: 

default:
	make exe

clean:
	rm -rf ./obj/*.o

run:
	./exe input/APf.txt