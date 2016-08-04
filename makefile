CC = g++
CFLAGS = -Wall -O2
CXXFLAGS = $(CFLAGS)
OBJS = complex.o

all: complex

complex: main.o $(OBJS) 
	$(CC) $(CXXFLAGS) -o complex main.o $(OBJS)

complex.o: complex.cpp
	$(CC) $(CXXFLAGS) -c complex.cpp

main.o: main.cpp
	$(CC) $(CXXFLAGS) -c main.cpp

dep:
	echo "hi"

clean:
	rm -f *.o complex

DEBUG:
	@echo "Debugger mode" 

help:
	@echo "This is makefile command information:"
	@echo "==============================================="
	@echo "all = compile all the file."
	@echo "DEBUG = enable the debugger mode."
	@echo "clean = remove executable and object file."
	@echo "==============================================="
	@echo 'Just use "make (FLAG)" then pass argument to make command.'
	@echo ""
