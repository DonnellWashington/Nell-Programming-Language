#include<ostream>
#include<iostream>
#include"Lexer.h"
#include"Lexer.cpp"

using namespace std;

int main(){

    std::string input = "print";
    Lexer lexer(input);
    std::vector<Token> tokens = lexer.Tokenize();

    
    lexer.printTokens(tokens);

    return 0;

}