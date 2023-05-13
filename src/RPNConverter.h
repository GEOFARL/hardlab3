#include <string>
#include <sstream>
#include <ctype.h>
#include "Stack.h"
#include "Operator.h"
#include "TokenParser.h"
#include "OperatorManager.h"

class RPNConverter
{
  std::string expression;
  Stack<std::string> stack;

public:
  RPNConverter(const std::string &);

  std::string convertToRPN();

private:
  bool isUnaryMinus(const std::string &);
  bool isNumeric(const std::string &);

  void handleOperator(const std::string &, std::string &);
  void handleClosingParenthesis(std::string &);

  bool hasLargerPrecedence(const std::string &, const std::string &);
};