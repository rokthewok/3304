#include "HexScanner.h"
#include "DigitToken.h"
#include "OperatorToken.h"
#include "InvalidToken.h"

HexScanner::HexScanner( std::istream * in )
	: m_in( in ) {

}

Token * HexScanner::getNextToken() {

	while( true ) {
		char nextChar = m_in->get();
		if( !m_in->good() ) {
			return nullptr;
		}

		if( this->isHexDigit( nextChar ) ) {
			unsigned int digit = this->parseDigit( nextChar );
			return new DigitToken( digit );
		} else if( this->isOperator( nextChar ) ) {
			return new OperatorToken( nextChar );
		} else if( nextChar == '\n' ) {
			// do nothing
		} else {
			return new InvalidToken( nextChar );
		}
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
