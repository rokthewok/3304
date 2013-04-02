# this is my makefile!

# VPATH = bin:include:src

GXX = g++

CFLAGS = -Wall -g -static -static-libgcc -static-libstdc++ -Iinclude

obj = HexScanner.o DigitToken.o InvalidToken.o Token.o NewlineToken.o HexParser.o AndToken.o OrToken.o NotToken.o \
      XorToken.o ShiftLeftToken.o ShiftRightToken.o LeftParenToken.o RightParenToken.o EmptyToken.o

project_one : main.o $(obj)
	$(GXX) $(CFLAGS) -o project_one main.o $(obj)
main.o : $(obj)
	$(GXX) $(CFLAGS) -c main.cpp -o main.o
HexParser.o : HexParser.h HexParser.cpp HexScanner.h HexScanner.o Token.h Token.o DigitToken.h DigitToken.o
	$(GXX) $(CFLAGS) -c HexParser.cpp -o HexParser.o
HexScanner.o : HexScanner.h HexScanner.cpp Token.h DigitToken.h DigitToken.o
	$(GXX) $(CFLAGS) -c HexScanner.cpp -o HexScanner.o
DigitToken.o : DigitToken.h DigitToken.cpp Token.h Token.o
	$(GXX) $(CFLAGS) -c DigitToken.cpp -o DigitToken.o
InvalidToken.o : InvalidToken.h InvalidToken.cpp Token.h Token.o
	$(GXX) $(CFLAGS) -c InvalidToken.cpp -o InvalidToken.o
NewlineToken.o : NewlineToken.h NewlineToken.cpp Token.h Token.o
	$(GXX) $(CFLAGS) -c NewlineToken.cpp -o NewlineToken.o
OrToken.o : OrToken.h OrToken.cpp Token.h Token.o
	$(GXX) $(CFLAGS) -c OrToken.cpp -o OrToken.o
AndToken.o : AndToken.h AndToken.cpp Token.h Token.o
	$(GXX) $(CFLAGS) -c AndToken.cpp -o AndToken.o
XorToken.o : XorToken.h XorToken.cpp Token.h Token.o
	$(GXX) $(CFLAGS) -c XorToken.cpp -o XorToken.o
NotToken.o : NotToken.h NotToken.cpp Token.h Token.o
	$(GXX) $(CFLAGS) -c NotToken.cpp -o NotToken.o
ShiftLeftToken.o : ShiftLeftToken.h ShiftLeftToken.cpp Token.h Token.o
	$(GXX) $(CFLAGS) -c ShiftLeftToken.cpp -o ShiftLeftToken.o
ShiftRightToken.o : ShiftRightToken.h ShiftRightToken.cpp Token.h Token.o
	$(GXX) $(CFLAGS) -c ShiftRightToken.cpp -o ShiftRightToken.o
LeftParenToken.o : LeftParenToken.h LeftParenToken.cpp Token.h Token.o
	$(GXX) $(CFLAGS) -c LeftParenToken.cpp -o LeftParenToken.o
RightParenToken.o : RightParenToken.h RightParenToken.cpp Token.h Token.o
	$(GXX) $(CFLAGS) -c RightParenToken.cpp -o RightParenToken.o
EmptyToken.o : EmptyToken.h EmptyToken.cpp Token.h Token.o
	$(GXX) $(CFLAGS) -c EmptyToken.cpp -o EmptyToken.o
Token.o : Token.h Token.cpp
	$(GXX) $(CFLAGS) -c Token.cpp -o Token.o
clean :
	rm -f *.o project_one
