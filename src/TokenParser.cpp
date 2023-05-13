#include "TokenParser.h"

namespace TokenParser
{
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
}
