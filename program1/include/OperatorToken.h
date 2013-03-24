#ifndef OPERATOR_TOKEN_H
#define OPERATOR_TOKEN_H
#include "Token.h"

class OperatorToken : public Token {
	public:
		OperatorToken();
		explicit OperatorToken( char op );
		const char getValue() const;
		void setValue( char op );
	private:
		char m_value;
};

#endif // OPERATOR_TOKEN_H
