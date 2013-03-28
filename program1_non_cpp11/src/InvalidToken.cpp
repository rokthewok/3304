#include "InvalidToken.h"

InvalidToken::InvalidToken()
	: Token::Token( Token::INVALID, " " ),
	  m_token( ' ' ) {

}

InvalidToken::InvalidToken( std::string token )
	: Token::Token( Token::INVALID, token ),
	  m_token( ' ' ) {

}

const char InvalidToken::getValue() const {
	return this->m_token;
}

void InvalidToken::setValue( char token ) {
	this->m_token = token;
}
