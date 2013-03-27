#ifndef TOKEN_H
#define TOKEN_H
#include <string>

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
			LEFT_PAREN,
			RIGHT_PAREN,
			NEWLINE,
			EMPTY,
			INVALID
		};
		Token( TokenType type, std::string str );
		virtual TokenType getTokenType() const;
		virtual std::string toString() const;
	private:
		TokenType m_type;
		std::string m_string;
};

#endif // TOKEN_H
