#include "HexParser.h"
#include "Token.h"
#include "DigitToken.h"

HexParser::HexParser( HexScanner * scanner )
	: m_scanner( scanner ),
	  m_token( NULL ),
	  m_stringResult( "" ) {

}

void HexParser::grabNextToken() {
	delete m_token;
	m_token = m_scanner->getNextToken();
	if( m_token->getTokenType() != Token::NEWLINE ) {
		m_stringResult += m_token->toString();
	}
}

unsigned int HexParser::E() {
	unsigned int subtotal = A();
	return this->EE( subtotal );
}

unsigned int HexParser::EE( unsigned int subtotal ) {
	switch( m_token->getTokenType() ) {
	case Token::OR:
		this->grabNextToken();
		subtotal = subtotal | this->A();
		subtotal = this->EE( subtotal );
		return subtotal;
		break;
	default:
		// empty string
		return subtotal;
		break;
	}
}

unsigned int HexParser::A() {
	unsigned int subtotal = this->B();
	return this->AA( subtotal );
}

unsigned int HexParser::AA( unsigned int subtotal ) {
	switch( m_token->getTokenType() ) {
	case Token::XOR:
		this->grabNextToken();
		subtotal = subtotal ^ this->B();
		subtotal = this->AA( subtotal );
		return this->AA( subtotal );
		break;
	default:
		// empty string
		return subtotal;
		break;
	}
}

unsigned int HexParser::B() {
	unsigned int subtotal = this->C();
	return this->BB( subtotal );
}

unsigned int HexParser::BB( unsigned int subtotal ) {
	switch( m_token->getTokenType() ) {
	case Token::AND:
		this->grabNextToken();
		subtotal = subtotal & this->C();
		subtotal = this->BB( subtotal );
		return this->BB( subtotal );
		break;
	default:
		// empty string
		return subtotal;
		break;
	}
}

unsigned int HexParser::C() {
	unsigned int subtotal = 0;

	switch( m_token->getTokenType() ) {
	case Token::DIGIT:
		subtotal = dynamic_cast<DigitToken *>( m_token )->getValue();
		this->grabNextToken();
		return subtotal;
		break;
	case Token::LEFT_PAREN:
		this->grabNextToken();
		subtotal = this->E();
		if( m_token->getTokenType() == Token::RIGHT_PAREN ) {
			this->grabNextToken();
			return subtotal;
		} else {
			// error
		}
		break;
	case Token::SHIFT_LEFT:
		this->grabNextToken();
		return ( this->C() << 1 ) & 0xF;
		break;
	case Token::SHIFT_RIGHT:
		this->grabNextToken();
		return ( this->C() >> 1 ) & 0xF;
		break;
	case Token::NOT:
		this->grabNextToken();
		return ~( this->C() ) & 0xF;
		break;
	default:
		//error
		break;
	}
}

unsigned int HexParser::parse() {
	m_token = m_scanner->getNextToken();
	m_stringResult = m_token->toString();

	if( m_scanner->isEndOfStream() && m_token->getTokenType() != Token::DIGIT ) {
		return -1;
	}

	return this->E();
}

std::string HexParser::getLastLine() {
	return m_stringResult;
}
