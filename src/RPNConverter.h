#include <iostream>
#include <string>
#include <sstream>
#include <ctype.h>
#include <unordered_map>
#include "Stack.h"

struct Operator
{
  std::string symbol;
  int precedence;
  bool isLeftAssociative;

  Operator() = default;
  Operator(const std::string &sym, int prec, bool isLeftAssoc)
      : symbol(sym), precedence{prec}, isLeftAssociative{isLeftAssoc} {}
};

template <typename T>
class RPNConverter
{
  std::string expression;
  Stack<std::string> stack;
  std::unordered_map<std::string, Operator> operators;

public:
  RPNConverter(const std::string &expr)
  {
    expression = removeWhiteSpaces(expr);
    expression = replaceUnaryMinuses(expression);
    initializeOperators();
  }

  std::string convertToRPN()
  {
    std::string rpnExpression;
    std::istringstream iss{expression};
    char character;
    std::string token;

    while (iss.get(character))
    {
      token = character;
      bool isUnMinus{false};
      if (isUnaryMinus(token))
      {
        isUnMinus = true;
      }
      else if (isOperator(token))
      {
        handleOperator(token, rpnExpression);
      }
      else if (token == "(")
      {
        stack.push(token);
      }
      else if (token == ")")
      {
        handleClosingParenthesis(rpnExpression);
      }
      if (isNumeric(token) || isUnMinus)
      {
        if (isUnMinus)
        {
          // Unary minus token is in the form of 'u'
          token = "-";
        }
        int nextChar = iss.peek();

        // Get the remaining of the number
        while (nextChar != EOF && (std::isdigit(nextChar) || nextChar == '.'))
        {
          iss.get(character);
          token += character;
          nextChar = iss.peek();
        }
        rpnExpression += token + " ";
      }
    }
    while (!stack.isEmpty())
    {
      rpnExpression += stack.top() + " ";
      stack.pop();
    }
    return rpnExpression;
  }

private:
  std::string removeWhiteSpaces(const std::string &expr)
  {
    std::stringstream ss;
    for (char c : expr)
    {
      if (!std::isspace(c))
      {
        ss << c;
      }
    }
    return ss.str();
  }

  std::string replaceUnaryMinuses(const std::string &expr)
  {
    std::string result = expr;

    for (size_t i = 0; i < result.length(); ++i)
    {
      if (result[i] == '-')
      {
        // Check if the minus sign is unary
        bool isUnaryMinus = (i == 0) || (result[i - 1] == '(') || (result[i - 1] == '+') || (result[i - 1] == '-') || (result[i - 1] == '*') || (result[i - 1] == '/');

        if (isUnaryMinus)
        {
          result[i] = 'u';
        }
      }
    }

    return result;
  }

  void initializeOperators()
  {
    operators.emplace("+", Operator("+", 2, true));
    operators.emplace("-", Operator("-", 2, true));
    operators.emplace("*", Operator("*", 3, true));
    operators.emplace("/", Operator("/", 3, true));
    operators.emplace("^", Operator("^", 4, false));
  }

  bool isOperator(const std::string &token)
  {
    return operators.find(token) != operators.end();
  }

  bool isUnaryMinus(const std::string &token)
  {
    return token == "u";
  }

  bool isNumeric(const std::string &token)
  {
    std::istringstream iss(token);
    double value;
    return iss >> value && iss.eof();
  }

  void handleOperator(const std::string &token, std::string &rpnExpression)
  {
    while (!stack.isEmpty() && isOperator(stack.top()) && hasLargerPrecedence(stack.top(), token))
    {
      rpnExpression += stack.top() + " ";
      stack.pop();
    }
    stack.push(token);
  }

  bool hasLargerPrecedence(const std::string &op1, const std::string &op2)
  {
    const Operator &operator1 = operators[op1];
    const Operator &operator2 = operators[op2];

    if (operator1.precedence > operator2.precedence)
    {
      return true;
    }
    if (operator1.precedence < operator2.precedence)
    {
      return false;
    }

    return operator1.isLeftAssociative;
  }

  void handleClosingParenthesis(std::string &rpnExpression)
  {
    while (!stack.isEmpty() && stack.top() != "(")
    {
      rpnExpression += stack.top() + " ";
      stack.pop();
    }
    if (!stack.isEmpty() && stack.top() == "(")
    {
      stack.pop();
    }
  }
};