#ifndef LEXER_H
#define LEXER_H

#include<string>

enum TokenType{
    TOK_LPAREN,
    TOK_PRINT,
    TOK_DIGIT,
    TOK_RPAREN,
    TOK_LQUOTA,
    TOK_RQUOTA,
    TOK_SEMIC,
};


struct Token{
    std::string value;
    TokenType type;

    Token(TokenType t, std::string v) : type(t), value(v) {}    // Constructor
};


#endif