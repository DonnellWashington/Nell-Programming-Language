#include<iostream>
#include<ostream>
#include<vector>
#include<string>
#include<cctype>
#include"lexer.h"


class Lexer {

public:
    // Lexer(const std::string& input);

    // A function to take input and tokenize it then return a vector of tokens
    std::vector<Token> tokenize(){
        std::vector<Token> tokens;
        std::string word = "";

        char currChar = input[pos];

        while (pos < input.size()){
            if (std::isspace(currChar)) pos++;
            // If we come across a char we need to keep reading it in until the end of the token or maybe until another token is reached
            else if (isalpha(currChar)){
                word += currChar;
                pos++;

                if (word == "print"){
                    tokens.emplace_back(TOK_PRINT, "print");
                }
                
                word = "";

            }
            

            else if (std::isdigit(currChar)){
                tokens.emplace_back(TOK_DIGIT, currChar);
                pos++;
            }
            
            else if (currChar == '('){
                tokens.emplace_back(TOK_LPAREN, currChar);
                pos++;
            }

            else if (currChar == ')'){
                tokens.emplace_back(TOK_RPAREN, currChar);
                pos++;
            }

            else {
                throw std::runtime_error("Unknown character");
            }
            
            
        }
        
        
        

        // Loop over the input
        // for (char c : input){
        //     char currentChar = input[pos];    // this line technically isnt needed c is the current char
        //     if (std::isspace(currentChar)){
        //         pos++;
        //     }
        //     // Check if the word is equal to print 
        //     else if (!std::isalpha(c)){
        //         word += c;
        //         if (word == "print"){
        //             tokens.push_back({ TOK_PRINT, "print"});
        //         }

        //         word = "";
                
        //     }
            
        // }
        
        return tokens;

    }


private:
    std::string input;
    size_t pos;

};
