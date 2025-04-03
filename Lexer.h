#ifndef LEXER_H
#define LEXER_H

#include<string>

enum TokenType{
    IDENT,
    LPAREN,
    TOK_PRINT,
    RPAREN,
    ENDLINE
};


struct Token{
    std::string value;
    TokenType type;

    Token(TokenType t, std::string v) : type(t), value(v) {}    // Constructor
};


#endif