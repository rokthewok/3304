#include <iostream>
#include <fstream>
#include <sstream>
#include "Token.h"
#include "HexScanner.h"
#include "HexParser.h"

int main( int argv, char ** argc ) {
	std::ifstream in;
	in.open( argc[1] );

	std::stringstream stream( "~(e^7)" );
	
	HexScanner scanner( &in );
	HexParser parser( &scanner );
	
	unsigned int result = 0;
	while( true ) {
		result = parser.parse();
		if( result != -1 ) {
			std::cout << parser.getLastLine() << " = ";
			std::cout << std::hex << result << std::endl;
		} else {
			break;
		}
	}

	return 0;
}
