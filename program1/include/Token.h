#ifndef TOKEN_H
#define TOKEN_H

class Token {
	public:
		enum class TokenType : unsigned char {
			DIGIT,
			OPERATOR,
			AND,
			OR,
			XOR,
			NOT,
			SHIFT_LEFT,
			SHIFT_RIGHT,
			NEWLINE,
			INVALID
		};
		explicit Token( TokenType type );
		virtual TokenType getTokenType() const;
	private:
		TokenType m_type;
};

#endif // TOKEN_H
