#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include "Token.h"
#include "HexScanner.h"
#include "HexParser.h"

int main( int argv, char ** argc ) {
//	std::ifstream in( stdin );
//	if( argv < 2 ) {
//		std::cout << "Please supply the appropriate command line arguments!" << std::endl;
//		return -1;
//	} else {
//		in.open( argc[1] );
//	}
	
	HexScanner scanner( &std::cin );
	HexParser parser( &scanner );
	
	unsigned int result = 0;
	while( true ) {
		result = parser.parse();
		if( result != -1 ) {
			//std::cout << std::setw(25) << std::setiosflags( std::ios::left ) << parser.getLastLine();
			//std::cout << std::resetiosflags( std::ios::left );
			std::cout << std::setw(5) << std::setiosflags( std::ios::right ) << " = " << std::hex << result << std::endl;
			std::cout << std::resetiosflags( std::ios::right );
		} else {
			break;
		}
	}

	return 0;
}
