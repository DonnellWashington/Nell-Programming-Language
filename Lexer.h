#ifndef LEXER_H
#define LEXER_H

#include<string>

enum TokenType{
    IDENT,
    LPAREN,
    PRINT,
    RPAREN,
    ENDLINE
};


struct Token{
    std::string value;
    TokenType type;
};


#endif