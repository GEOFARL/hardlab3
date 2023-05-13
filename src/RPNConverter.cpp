#include "RPNConverter.h"

RPNConverter::RPNConverter(const std::string &expr) : expression(expr)
{
  expression = TokenParser::removeWhiteSpaces(expression);
  expression = TokenParser::replaceUnaryMinuses(expression);
}

std::string RPNConverter::convertToRPN()
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
    else if (OperatorManager::isOperator(token))
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

bool RPNConverter::isUnaryMinus(const std::string &token)
{
  return token == "u";
}

bool RPNConverter::isNumeric(const std::string &token)
{
  std::istringstream iss(token);
  double value;
  return iss >> value && iss.eof();
}

void RPNConverter::handleOperator(const std::string &token, std::string &rpnExpression)
{
  while (!stack.isEmpty() && OperatorManager::isOperator(stack.top()) && hasLargerPrecedence(stack.top(), token))
  {
    rpnExpression += stack.top() + " ";
    stack.pop();
  }
  stack.push(token);
}

bool RPNConverter::hasLargerPrecedence(const std::string &op1, const std::string &op2)
{
  const Operator &operator1 = OperatorManager::getOperator(op1);
  const Operator &operator2 = OperatorManager::getOperator(op2);

  if (operator1.getPrecedence() > operator2.getPrecedence())
  {
    return true;
  }
  if (operator1.getPrecedence() < operator2.getPrecedence())
  {
    return false;
  }

  return operator1.isLeftAssociative();
}

void RPNConverter::handleClosingParenthesis(std::string &rpnExpression)
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
