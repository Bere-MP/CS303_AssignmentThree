#pragma once

#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

// Functions defined
bool isOpening(char ch);
bool isClosing(char ch);
bool ParenthesesMatching(char opening, char closing);
bool isBalanced(const char* exp);
int precedence(char symbol);
string infixToPostfix(const char* infix);
