#ifndef DIGIT_TOKEN_H
#define DIGIT_TOKEN_H
#include "Token.h"

class DigitToken : public Token {
	public:
		DigitToken();
		explicit DigitToken( unsigned int value );
		const unsigned int getValue() const;
		void setValue( unsigned int value );
	private:
		unsigned int m_value;
};

#endif // DIGIT_TOKEN_H
