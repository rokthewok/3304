#ifndef TOKEN_H
#define TOKEN_H

class Token {
	public:
		enum class TokenType : unsigned char {
			DIGIT,
			OPERATOR,
			INVALID
		};
		explicit Token( TokenType type );
		virtual TokenType getTokenType() const;
	private:
		TokenType m_type;
};

#endif // TOKEN_H
