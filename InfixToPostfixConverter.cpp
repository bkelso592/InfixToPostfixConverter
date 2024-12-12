#include "InfixToPostfixConverter.h"
#include <stack>
#include <cctype>  // for isalpha function

void InfixToPostfixConverter::convert(const std::string& infix) {
    std::stack<char> operators;
    postfixExpression.clear();

    for (size_t i = 0; i < infix.size(); ++i) {
        char currentChar = infix[i];

        if (std::isalpha(currentChar)) {
            postfixExpression += currentChar;
        }
        else if (currentChar == '(') {
            operators.push(currentChar);
        }
        else if (currentChar == ')') {
            while (!operators.empty() && operators.top() != '(') {
                postfixExpression += operators.top();
                operators.pop();
            }
            if (!operators.empty()) operators.pop();
        }
        else if (isOperator(currentChar)) {
            while (!operators.empty() && precedence(currentChar) <= precedence(operators.top())) {
                postfixExpression += operators.top();
                operators.pop();
            }
            operators.push(currentChar);
        }
    }

    while (!operators.empty()) {
        postfixExpression += operators.top();
        operators.pop();
    }
}

int InfixToPostfixConverter::precedence(char op) {
    switch (op) {
    case '+':
    case '-': return 1;
    case '*':
    case '/': return 2;
    default: return 0;
    }
}

bool InfixToPostfixConverter::isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

std::string InfixToPostfixConverter::getPostfix() const {
    return postfixExpression;
}