# this is my makefile!

VPATH = bin:include:src

CFLAGS = -g -Iinclude -std=c++11

incl = include/
src = src/
bin = bin/

obj = HexScanner.o DigitToken.o OperatorToken.o InvalidToken.o Token.o
binobj = $(bin)HexScanner.o $(bin)DigitToken.o $(bin)OperatorToken.o $(bin)main.o $(bin)Token.o $(bin)InvalidToken.o

project_one : main.o $(obj)
	g++ -o project_one $(binobj)
main.o : $(obj)
	g++ $(CFLAGS) -c $(src)main.cpp -o $(bin)main.o
HexScanner.o : HexScanner.h HexScanner.cpp Token.h DigitToken.h OperatorToken.h DigitToken.o OperatorToken.o
	g++ $(CFLAGS) -c $(src)HexScanner.cpp -o $(bin)HexScanner.o
DigitToken.o : DigitToken.h DigitToken.cpp Token.h Token.o
	g++ $(CFLAGS) -c $(src)DigitToken.cpp -o $(bin)DigitToken.o
OperatorToken.o : OperatorToken.h OperatorToken.cpp Token.h Token.o
	g++ $(CFLAGS) -c $(src)OperatorToken.cpp -o $(bin)OperatorToken.o
InvalidToken.o : InvalidToken.h InvalidToken.cpp Token.h Token.o
	g++ $(CFLAGS) -c $(src)InvalidToken.cpp -o $(bin)InvalidToken.o
Token.o : Token.h Token.cpp
	g++ $(CFLAGS) -c $(src)Token.cpp -o $(bin)Token.o
clean :
	rm -f bin/* project_one
