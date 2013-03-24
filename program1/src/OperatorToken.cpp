#include "OperatorToken.h"

OperatorToken::OperatorToken()
	: OperatorToken::OperatorToken( '&' ) {

}

OperatorToken::OperatorToken( char op )
	: Token::Token( Token::TokenType::OPERATOR ),
	  m_value( op ) {

}

const char OperatorToken::getValue() const {
	return this->m_value;
}

void OperatorToken::setValue( char op ) {
	this->m_value = op;
}
