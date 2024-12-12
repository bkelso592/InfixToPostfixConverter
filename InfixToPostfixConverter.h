#ifndef INFIXTOPREFIXCONVERTER_H
#define INFIXTOPREFIXCONVERTER_H

#include <string>

class InfixToPostfixConverter {
private:
    std::string postfixExpression;  // Stores the resulting postfix expression

public:
    void convert(const std::string& infix);
    int precedence(char op);
    bool isOperator(char ch);
    std::string getPostfix() const;
};

#endif