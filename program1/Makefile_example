# Argonaut C++ Makefile

VPATH = src:include:bin

CFLAGS = -g -Iinclude -std=c++11

incl = include/
src = src/
bin = bin/

obj = argonaut.o JsonScanner.o Reader.o #SyntaxException.o
binobj = $(bin)argonaut.o $(bin)JsonScanner.o $(bin)Reader.o #$(bin)SyntaxException.o

argonaut : $(obj)
	g++ -o argonaut $(binobj)
argonaut.o : argonaut.cpp JsonScanner.o
	g++ $(CFLAGS) -c $(src)argonaut.cpp -o $(bin)argonaut.o
#SyntaxException.o : SyntaxException.h
#	g++ $(CFLAGS) -c $(incl)SyntaxException.h -o $(bin)SyntaxException.o
JsonScanner.o : JsonScanner.h JsonScanner.cpp Reader.o SyntaxException.h
	g++ $(CFLAGS) -c $(src)JsonScanner.cpp -o $(bin)JsonScanner.o
Reader.o : Reader.h Reader.cpp
	g++ $(CFLAGS) -c $(src)Reader.cpp -o $(bin)Reader.o
test :
	# TODO build all test classes and main test file
clean :
	rm -f bin/*.o argonaut
