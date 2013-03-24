#ifndef INVALID_TOKEN_H
#define INVALID_TOKEN_H
#include "Token.h"

class InvalidToken : public Token {
	public:
		InvalidToken();
		explicit InvalidToken( char token );
		const char getValue() const;
		void setValue( char token );
	private:
		char m_token;
};

#endif // INVALID_TOKEN_H
