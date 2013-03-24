#include <iostream>
#include <sstream>
#include "Token.h"
#include "DigitToken.h"
#include "OperatorToken.h"
#include "InvalidToken.h"
#include "HexScanner.h"

int main( int argv, char ** argc ) {
	std::cout << "Hello world!" << std::endl;

	Token * digitToken = new DigitToken( 10 );
	Token * opToken = new OperatorToken( '^' );
	
	if( digitToken->getTokenType() == Token::TokenType::DIGIT ) {
		std::cout << dynamic_cast<DigitToken *>( digitToken )->getValue() << std::endl;
	}

	if( opToken->getTokenType() == Token::TokenType::OPERATOR ) {
		std::cout << dynamic_cast<OperatorToken *>( opToken )->getValue() << std::endl;
	}

	std::stringstream stream( "3Pa" );
	
	HexScanner scanner( &stream );

	Token * token;

	token = scanner.getNextToken();
	while( token != nullptr ) {
		if( token->getTokenType() == Token::TokenType::DIGIT ) {
			std::cout << dynamic_cast<DigitToken *>( token )->getValue() << std::endl;
		} else if( token->getTokenType() == Token::TokenType::OPERATOR ) {
			std::cout << dynamic_cast<OperatorToken *>( token )->getValue() << std::endl;
		} else {
			std::cout << "Invalid token: " << dynamic_cast<InvalidToken *>( token )->getValue() << std::endl;
		}
		
		delete token;
		token = scanner.getNextToken();
	}

	delete digitToken;
	delete opToken;

	return 0;
}
