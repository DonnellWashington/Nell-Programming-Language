#include<iostream>
#include<ostream>
#include<vector>
#include<string>
#include<cstring>
#include<unordered_map>
#include"lexer.h"

class Lexer{

public:
    Lexer(const std::string& src) : input(src){}

    // A function to take input and then extract the tokens from it and put them into a vector
    std::vector<Token> Tokenize(const char* syn){
        std::string token = "";

        TokenType type = tokenWords[token];

        size_t len = strlen(syn);

        for(size_t i = 0; i < len; i++){
            char currChar = syn[i];

            // First we need to skip the spaces
            if (isspace(currChar)) skipSpaces(pos);

            else if (isalpha(currChar)){
                token += currChar;

                if (token == "print"){
                    tokens.push_back(Token{TOK_PRINT, "print"});
                    token = "";
                }
                
            }
            
        }
        return tokens;
    }

    // I will probably add a function to check the parens here


    // Function to skip white space
    void skipSpaces(int *pos){
        if (isspace(*pos)) pos++;
    }

    // A function to print the token that have been retreived from input
    void printTokens(const std::vector<Token>& tokens){
        for (const Token& token : tokens){
            std::cout << reverseTokenWords[token.type] << ": " << token.value << std::endl;
        }
    }

private:

    std::vector<Token> tokens;
    std::string input;

    int *pos = 0;
    
    std::unordered_map<TokenType, std::string> reverseTokenWords = {
        {TOK_PRINT, "TOK_PRINT"},
        {TOK_LPAREN, "TOK_LPAREN"},
        {TOK_RPAREN, "TOK_RPAREN"},
        {TOK_LQUOTA, "TOK_LQUOTA"},
        {TOK_RQUOTA, "TOK_RQUOTA"},
        {TOK_SEMIC, "TOK_SEMIC"},
        {TOK_IF, "TOK_IF"},
        {TOK_WHILE, "TOK_WHILE"},
        {TOK_FOR, "TOK_FOR"},
    };

    std::unordered_map<std::string, TokenType> tokenWords = {
        {"print", TOK_PRINT},
        {"(", TOK_LPAREN},
        {")", TOK_RPAREN},
        {"\"", TOK_LQUOTA},
        {"\"", TOK_RQUOTA},
        {";", TOK_SEMIC},
        {"if", TOK_IF},
        {"while", TOK_WHILE},
        {"for", TOK_FOR},

    };

};
