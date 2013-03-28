#ifndef HEX_PARSER_H
#define HEX_PARSER_H
#include <istream>
#include <string>
#include "HexScanner.h"

class HexParser {
	public:
		HexParser( HexScanner * scanner );
		virtual unsigned int parse();
		std::string getLastLine();
	private:
		unsigned int E();
		unsigned int EE( unsigned int subtotal );
		unsigned int A();
		unsigned int AA( unsigned int subtotal );
		unsigned int B();
		unsigned int BB( unsigned int subtotal );
		unsigned int C();
		void grabNextToken();

		HexScanner * m_scanner;
		Token * m_token;
		std::string m_stringResult;
};

#endif // HEX_PARSER_H
