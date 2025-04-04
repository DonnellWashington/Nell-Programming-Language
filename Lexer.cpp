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

                //Stick to the thing and just make tokens spilt them into tokens and put them into the uh vector
                case TOK_PRINT:
                    tokens.emplace_back( TOK_PRINT, "print");
                    if (input[nextChar] == '('){
                        tokens.push_back(Token{TOK_LPAREN, "("});
                    }
                    break;
                
                case TOK_LPAREN:
                    tokens.push_back(Token{ TOK_LPAREN, "("});
                    break;
                
                case TOK_RPAREN:
                    tokens.push_back(Token{ TOK_RPAREN, ")"});
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

                
                case TOK_LQUOTA:
                    tokens.push_back(Token{ TOK_LQUOTA, "\""});
                    break;
                
                case TOK_RQUOTA:
                    tokens.push_back(Token{ TOK_LQUOTA, "\""});
                    break;

                default:
                    // Throw an error here if the value they entered wasnt right I guess...
                    
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
