#include<ostream>
#include<iostream>
#include"Lexer.h"
#include"Lexer.cpp"

using namespace std;

int main(){

    const char* input = "print(\"Hellow World\");";
    Lexer lexer(input);
    std::vector<Token> tokens = lexer.Tokenize(input);

    lexer.printTokens(tokens);

    return 0;

}