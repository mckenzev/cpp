#include "utils.h"

#include <sstream>

namespace s21 {

double ParseStrToDouble(const std::string& str) {
  std::string tmp = str;
  size_t pos = tmp.find(",");
  if (pos != std::string::npos) {
    tmp.at(pos) = '.';
  }
  std::istringstream iss(tmp);
  double result;
  iss >> result;
  return result;
}

}  // namespace s21
