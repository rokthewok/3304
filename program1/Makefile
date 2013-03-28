# this is my makefile!

VPATH = bin:include:src

GXX = g++

CFLAGS = -v -Wall -g -static-libgcc -static-libstdc++ -Iinclude -std=c++11

incl = include/
src = src/
bin = bin/

obj = HexScanner.o DigitToken.o InvalidToken.o Token.o NewlineToken.o HexParser.o AndToken.o OrToken.o NotToken.o \
      XorToken.o ShiftLeftToken.o ShiftRightToken.o LeftParenToken.o RightParenToken.o EmptyToken.o
binobj = $(bin)HexScanner.o $(bin)DigitToken.o $(bin)main.o $(bin)Token.o $(bin)InvalidToken.o $(bin)NewlineToken.o $(bin)HexParser.o \
	     $(bin)AndToken.o $(bin)OrToken.o $(bin)NotToken.o $(bin)XorToken.o $(bin)ShiftLeftToken.o $(bin)ShiftRightToken.o $(bin)LeftParenToken.o \
		 $(bin)RightParenToken.o $(bin)EmptyToken.o

project_one : main.o $(obj)
	$(GXX) $(CFLAGS) -o project_one $(binobj)
main.o : $(obj)
	$(GXX) $(CFLAGS) -c $(src)main.cpp -o $(bin)main.o
HexParser.o : HexParser.h HexParser.cpp HexScanner.h HexScanner.o Token.h Token.o DigitToken.h DigitToken.o
	$(GXX) $(CFLAGS) -c $(src)HexParser.cpp -o $(bin)HexParser.o
HexScanner.o : HexScanner.h HexScanner.cpp Token.h DigitToken.h DigitToken.o
	$(GXX) $(CFLAGS) -c $(src)HexScanner.cpp -o $(bin)HexScanner.o
DigitToken.o : DigitToken.h DigitToken.cpp Token.h Token.o
	$(GXX) $(CFLAGS) -c $(src)DigitToken.cpp -o $(bin)DigitToken.o
InvalidToken.o : InvalidToken.h InvalidToken.cpp Token.h Token.o
	$(GXX) $(CFLAGS) -c $(src)InvalidToken.cpp -o $(bin)InvalidToken.o
NewlineToken.o : NewlineToken.h NewlineToken.cpp Token.h Token.o
	$(GXX) $(CFLAGS) -c $(src)NewlineToken.cpp -o $(bin)NewlineToken.o
OrToken.o : OrToken.h OrToken.cpp Token.h Token.o
	$(GXX) $(CFLAGS) -c $(src)OrToken.cpp -o $(bin)OrToken.o
AndToken.o : AndToken.h AndToken.cpp Token.h Token.o
	$(GXX) $(CFLAGS) -c $(src)AndToken.cpp -o $(bin)AndToken.o
XorToken.o : XorToken.h XorToken.cpp Token.h Token.o
	$(GXX) $(CFLAGS) -c $(src)XorToken.cpp -o $(bin)XorToken.o
NotToken.o : NotToken.h NotToken.cpp Token.h Token.o
	$(GXX) $(CFLAGS) -c $(src)NotToken.cpp -o $(bin)NotToken.o
ShiftLeftToken.o : ShiftLeftToken.h ShiftLeftToken.cpp Token.h Token.o
	$(GXX) $(CFLAGS) -c $(src)ShiftLeftToken.cpp -o $(bin)ShiftLeftToken.o
ShiftRightToken.o : ShiftRightToken.h ShiftRightToken.cpp Token.h Token.o
	$(GXX) $(CFLAGS) -c $(src)ShiftRightToken.cpp -o $(bin)ShiftRightToken.o
LeftParenToken.o : LeftParenToken.h LeftParenToken.cpp Token.h Token.o
	$(GXX) $(CFLAGS) -c $(src)LeftParenToken.cpp -o $(bin)LeftParenToken.o
RightParenToken.o : RightParenToken.h RightParenToken.cpp Token.h Token.o
	$(GXX) $(CFLAGS) -c $(src)RightParenToken.cpp -o $(bin)RightParenToken.o
EmptyToken.o : EmptyToken.h EmptyToken.cpp Token.h Token.o
	$(GXX) $(CFLAGS) -c $(src)EmptyToken.cpp -o $(bin)EmptyToken.o
Token.o : Token.h Token.cpp
	$(GXX) $(CFLAGS) -c $(src)Token.cpp -o $(bin)Token.o
clean :
	rm -f bin/* project_one
