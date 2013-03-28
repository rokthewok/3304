#include "DigitToken.h"

DigitToken::DigitToken()
	: Token::Token( Token::DIGIT, "0" ),
	  m_value( 0 ) {

}

DigitToken::DigitToken( unsigned int value, std::string str )
	: Token::Token( Token::DIGIT, str ),
	  m_value( value ) {

}

const unsigned int DigitToken::getValue() const {
	return this->m_value;
}

void DigitToken::setValue( unsigned int value ) {
	this->m_value = value;
}
