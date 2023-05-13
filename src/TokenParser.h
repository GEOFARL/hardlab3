#pragma once

#include <string>
#include <sstream>
#include <cctype>

namespace TokenParser
{
  std::string removeWhiteSpaces(const std::string &expr);
  std::string replaceUnaryMinuses(const std::string &expr);
}
