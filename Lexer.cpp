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
        std::string stringLit = "";

        size_t synLen = strlen(syn);

        for(size_t i = 0; i < synLen; i++){
            char currChar = syn[i];
            char nextChar = syn[i + 1];

            // First we need to skip the spaces if any...
            if (isspace(currChar)){
                continue;
            } 

            else if (std::isalpha(currChar)){
                token += currChar;

                if (token == "print"){
                    tokens.push_back(Token{TOK_PRINT, "print"});
                    token = "";
                }
            }
            else if (currChar == '('){
                tokens.push_back(Token{TOK_LPAREN, "("});
                token = "";
            }
            else if (currChar == '\"'){
                tokens.push_back(Token{TOK_LQUOTA, "\""});
                i++;
                // Check for the string litreral
                stringLit = "";
                // Loop over the input while not at the end and not ending quotes
                // Check if ending quotes are reached and push stringLit and ending/ right quote to vector 
                while(i < synLen && syn[i] != '\"'){
                    stringLit += syn[i];
                    i++;
                }

                if (i < synLen && syn[i] == '\"'){
                    tokens.push_back(Token{TOK_DATA, stringLit});
                    tokens.push_back(Token{TOK_RQUOTA, "\""});
                }
                
            }
            else if (currChar == ')'){
                tokens.push_back(Token{TOK_RPAREN, ")"});
                token = "";
            }
            else if (currChar == ';'){
                tokens.push_back(Token{TOK_SEMIC, ";"});
                token = "";
            }
            
        }
        return tokens;
    }

    // I will probably add a function to check the parens here


    // Function to skip white space(not needed now but may come in handy later)
    // void skipSpaces(int *pos){
    //     if (isspace(*pos)) pos++;
    // }

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
        {TOK_DATA, "TOK_DATA"},
        {TOK_LQUOTA, "TOK_LQUOTA"},
        {TOK_RQUOTA, "TOK_RQUOTA"},
        {TOK_SEMIC, "TOK_SEMIC"},
        {TOK_IF, "TOK_IF"},
        {TOK_WHILE, "TOK_WHILE"},
        {TOK_FOR, "TOK_FOR"},
    };

};
