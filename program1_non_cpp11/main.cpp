#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include "Token.h"
#include "HexScanner.h"
#include "HexParser.h"

int main( int argv, char ** argc ) {
	HexScanner scanner( &std::cin );
	HexParser parser( &scanner );
	
	unsigned int result = 0;
	while( true ) {
		result = parser.parse();
		if( result != -1 ) {
			std::cout << std::setw(6) << std::setiosflags( std::ios::right ) << " =  " << std::hex << result << std::endl;
			std::cout << std::resetiosflags( std::ios::right );
		} else {
			break;
		}
	}

	return 0;
}
