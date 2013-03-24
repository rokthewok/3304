#include "Token.h"

Token::Token( TokenType type )
	: m_type( type ) {

}

Token::TokenType Token::getTokenType() const {
	return this->m_type;
}
