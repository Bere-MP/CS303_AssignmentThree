#include "function.h"

// Function checks if there is an opening parathesis
bool isOpening(char ch) {
  if (ch == '{' || ch == '(' || ch == '[')
    return true;
  else
    return false;
}

// Function checks if there is a closing parathesis
bool isClosing(char ch) {
  if (ch == '}' || ch == ')' || ch == ']')
    return true;
  else
    return false;
}

// Function checks if there are matching parathesis
bool ParenthesesMatching(char opening, char closing) {
  if ((opening == '{' && closing == '}') ||
      (opening == '(' && closing == ')') || (opening == '[' && closing == ']'))
    return true;
  else
    return false;
}

// Function checks if the parathesis are balanced
bool isBalanced(const char *exp) {
  stack<char> Sta;
  int length = strlen(exp);

  for (int i = 0; i < length; i++) {
    if (isOpening(exp[i]))
      Sta.push(exp[i]);
      
    else if (isClosing(exp[i])) {
      if (Sta.empty() || !ParenthesesMatching(Sta.top(), exp[i]))
        return false;
      
      Sta.pop();
    }
  }
  return Sta.empty();
}

// Function to return precedence
int precedence(char symbol) {
  if (symbol == '+' || symbol == '-')
    return 1;

  else if (symbol == '*' || symbol == '/' || symbol == '%')
    return 2;

  else
    return 0;
}

// Function to convert infix to postfix
string infixToPostfix(const char *infix) {
  string postfix;
  stack<char> Sta;

  int length = strlen(infix);

  for (int i = 0; i < length; i++) {
    if (isalnum(infix[i])) 
      postfix = postfix + infix[i];
      
    else if (infix[i] == '(') 
      Sta.push(infix[i]);
      
    else if (infix[i] == ')') {
      while (!Sta.empty() && Sta.top() != '(') {
        postfix = postfix + Sta.top();
        Sta.pop();
      }
      Sta.pop();
    } 
    
    else {
      while (!Sta.empty() && Sta.top() != '(' && Sta.top() != ')' &&
             (precedence(Sta.top()) >= precedence(infix[i]))) {
        postfix = postfix + Sta.top();
        Sta.pop();
      }
      Sta.push(infix[i]);
    }
  }

  while (!Sta.empty()) {
    postfix = postfix + Sta.top();
    Sta.pop();
  }

  return postfix;
}

/*
References:
- https://www.geeksforgeeks.org/stack-in-cpp-stl/
- https://www.geeksforgeeks.org/convert-infix-expression-to-postfix-expression/
- https://www.tutorialspoint.com/Convert-Infix-to-Postfix-Expression
- https://cplusplus.com/reference/cctype/isalnum/
*/
