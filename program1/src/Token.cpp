#include "Token.h"

Token::Token( TokenType type, std::string str )
	: m_type( type ),
	  m_string( str ) {

}

Token::TokenType Token::getTokenType() const {
	return this->m_type;
}

std::string Token::toString() const {
	return m_string;
}
