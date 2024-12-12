#include <iostream>
#include <fstream>
#include <string>
#include "InfixToPostfixConverter.h"

int main() {
    std::ifstream inputFile("InfixData.txt");
    if (!inputFile) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    InfixToPostfixConverter converter;
    std::string infixExpression;

    while (std::getline(inputFile, infixExpression)) {
        std::cout << "Infix Expression: " << infixExpression << std::endl;

        // Convert to postfix
        converter.convert(infixExpression);

        std::cout << "Postfix Expression: " << converter.getPostfix() << std::endl;
        std::cout << std::endl;  // Print an empty line between expressions
    }

    inputFile.close();
    return 0;
}