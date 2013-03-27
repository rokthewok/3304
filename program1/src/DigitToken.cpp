#include "DigitToken.h"

DigitToken::DigitToken()
	: DigitToken::DigitToken( 0, "0" ) {

}

DigitToken::DigitToken( unsigned int value, std::string str )
	: Token::Token( Token::TokenType::DIGIT, str ),
	  m_value( value ) {

}

const unsigned int DigitToken::getValue() const {
	return this->m_value;
}

void DigitToken::setValue( unsigned int value ) {
	this->m_value = value;
}
