#include <string>
#include <sstream>
#include <iostream>
#include "HexScanner.h"
#include "DigitToken.h"
#include "InvalidToken.h"
#include "NewlineToken.h"
#include "OrToken.h"
#include "XorToken.h"
#include "AndToken.h"
#include "NotToken.h"
#include "ShiftLeftToken.h"
#include "ShiftRightToken.h"
#include "LeftParenToken.h"
#include "RightParenToken.h"
#include "EmptyToken.h"

HexScanner::HexScanner( std::istream * in )
	: m_in( in ) {

}

bool HexScanner::isEndOfStream() {
	if( m_in->eof() ) {
		return true;
	} else {
		return false;
	}
}

Token * HexScanner::getNextToken() {
	char nextChar = m_in->get();
	if( !m_in->good() ) {
		return new EmptyToken();
	}

	if( this->isHexDigit( nextChar ) ) {
		std::stringstream ss;
		std::string s;
		ss << nextChar;
		ss >> s;
		unsigned int digit = this->parseDigit( nextChar );
		std::cout << nextChar;
		return new DigitToken( digit, s );
	} else if( this->isOperator( nextChar ) ) {
		std::cout << nextChar;
		return this->createOperatorToken( nextChar );
	} else if( nextChar == '\n' ) {
		return new NewlineToken();
	} else {
		std::stringstream ss;
		std::string s;
		ss << nextChar;
		ss >> s;
		return new InvalidToken( s );
	}
}

bool HexScanner::isHexDigit( char c ) {
	std::string validChars = "0123456789abcdef";
	
	return validChars.find( c ) != std::string::npos ? true : false;
}

bool HexScanner::isOperator( char c ) {
	std::string validChars = "|^&<>~()";

	return validChars.find( c ) != std::string::npos ? true : false;
}

unsigned int HexScanner::parseDigit( char c ) {
	switch( c ) {
	case 'a':
		return 0xA;
	case 'b':
		return 0xB;
	case 'c':
		return 0xC;
	case 'd':
		return 0xD;
	case 'e':
		return 0xE;
	case 'f':
		return 0xF;
	default:
		return c - '0';
	};
}

Token * HexScanner::createOperatorToken( char c ) {
	switch( c ) {
	case '|':
		return new OrToken();
	case '^':
		return new XorToken();
	case '&':
		return new AndToken();
	case '<':
		return new ShiftLeftToken();
	case '>':
		return new ShiftRightToken();
	case '~':
		return new NotToken();
	case '(':
		return new LeftParenToken();
	case ')':
		return new RightParenToken();
	default:
		std::stringstream ss;
		std::string s;
		ss << c;
		ss >> s;
		return new InvalidToken( s );
		break;
	};
}
