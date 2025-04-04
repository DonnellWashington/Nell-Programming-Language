#include<iostream>
#include<ostream>
#include<vector>
#include<string>
#include<unordered_map>
#include"lexer.h"




class Lexer{

public:
    // A function to take input and then extract the tokens from it and put them into a vector
    std::vector<Token> Tokenize(){
        std::vector<Token> tokens;
        std::string token = "";

        TokenType type = tokenWords[token];

        char currChar = pos;
        char nextChar = pos + 1;
        int inputSize = input.length();

        while(currChar != inputSize){
            if (isspace(currChar)) pos++;

            else if (isalpha(currChar)){
                token += currChar;
                
                switch (type){
                case TOK_PRINT:
                    tokens.emplace_back( TOK_PRINT, "print");
                    if (input[nextChar] == '('){
                        tokens.push_back(Token{TOK_LPAREN, "("});
                    }
                    break;
                
                case TOK_IF:
                    tokens.emplace_back( TOK_IF, "if");
                    if (input[nextChar] == '('){
                        tokens.push_back(Token{TOK_LPAREN, "("});
                    }
                    break;
                
                case TOK_SEMIC:
                    tokens.push_back(Token{ TOK_SEMIC, ";"});
                    break;
                
                case TOK_LPAREN:
                    tokens.push_back(Token{ TOK_LPAREN, "("});
                    break;

                    // We need to find the quotation and know thats its data to print and not a token

                    

                // // If we encounter a quotes we need to know that the user wants to print that data
                // // And it cant be mistaken for a token
                // case TOK_LQUOTA:
                //     tokens.emplace_back( TOK_DAT, 

                
                default:
                    break;
                }
                
            }
            
            
        }

        return tokens;

    }

    // I will probably add a function to check the parens here


    // And maybe one to skip white space here

private:

    size_t pos = 0;

    std::string input;

    // NEED TO UPDATE THE KEYS HERE!
    std::unordered_map<std::string, TokenType> tokenWords = {
        {"print", TOK_PRINT},
        {"(", TOK_LPAREN},
        {")", TOK_RPAREN},
        {"\"", TOK_LQUOTA},
        {"\"", TOK_RQUOTA},
        {";", TOK_SEMIC},

    };

};
