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

        // Loop over the input
        for (char c : input){
            char currentChar = input[pos];    // this line technically isnt needed c is the current char
            if (std::isspace(currentChar)){
                pos++;
            }
            // Check if the word is equal to print 
            else if (!std::isalpha(c)){
                word += c;
                if (word == "print"){
                    tokens.push_back({ TOK_PRINT, "print"});
                }

                word = "";
                
            }
            
        }
        
        return tokens;

    }


private:
    std::string input;
    size_t pos;

};
