#ifndef HEX_SCANNER_H
#define HEX_SCANNER_H
#include <istream>
#include "Token.h"

class HexScanner {
	public:
		explicit HexScanner( std::istream * in );
		Token * getNextToken();
	private:
		bool isHexDigit( char c );
		bool isOperator( char c );
		unsigned int parseDigit( char c );
		std::istream * m_in;
};

#endif // HEX_SCANNER_H
