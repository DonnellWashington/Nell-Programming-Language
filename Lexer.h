#ifndef LEXER_H
#define LEXER_H

#include<string>

enum TokenType{
    // IDENT,
    TOK_LPAREN,
    TOK_PRINT,
    TOK_DIGIT,
    TOK_RPAREN,
    // TOK_ENDLINE
};


struct Token{
    std::string value;
    TokenType type;

    Token(TokenType t, std::string v) : type(t), value(v) {}    // Constructor
};


#endif