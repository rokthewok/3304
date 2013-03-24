#include "InvalidToken.h"

InvalidToken::InvalidToken()
	: InvalidToken::InvalidToken( ' ' ) {

}

InvalidToken::InvalidToken( char token )
	: Token::Token( Token::TokenType::INVALID ),
	  m_token( token ) {

}

const char InvalidToken::getValue() const {
	return this->m_token;
}

void InvalidToken::setValue( char token ) {
	this->m_token = token;
}
