#include "model_calculation.h"

#include <cmath>
#include <cstring>
#include <map>
#include <sstream>

namespace s21 {

void Model::Calculation::InfixToPostfix() {
  postfix_.clear();  // Очистка постфиксного выражения при каждом вызове метода
  std::stack<char> stack;
  auto it = infix_.begin();
  while (it != infix_.end()) {
    switch (GetSymbolType(*it)) {
      case SymbolType::kOperator:
        OperatorHandling(stack, it);
        break;
      case SymbolType::kOperand:
        OperandOperation(it);
        break;
      case SymbolType::kOpenParenthesis:
        OpeningParenthesis(stack, it);
        break;
      case SymbolType::kCloseParenthesis:
        ClosingParenthesis(stack);
        break;
      default:
        throw std::runtime_error("Invalid character in infix");
        break;
    }
    ++it;
  }
  StackClearing(stack);
}

Model::Calculation::SymbolType Model::Calculation::GetSymbolType(
    const char c) const {
  static const std::map<char, SymbolType> kOps = {
      {'+', kOperator},        {'-', kOperator},        {'*', kOperator},
      {'/', kOperator},        {'^', kOperator},        {'%', kOperator},
      {'r', kOperator},        {'s', kOperator},        {'c', kOperator},
      {'t', kOperator},        {'S', kOperator},        {'C', kOperator},
      {'T', kOperator},        {'n', kOperator},        {'l', kOperator},
      {'x', kOperand},         {'1', kOperand},         {'2', kOperand},
      {'3', kOperand},         {'4', kOperand},         {'5', kOperand},
      {'6', kOperand},         {'7', kOperand},         {'8', kOperand},
      {'9', kOperand},         {'0', kOperand},         {'.', kOperand},
      {'(', kOpenParenthesis}, {')', kCloseParenthesis}};
  auto it = kOps.find(c);
  return (it != kOps.end()) ? it->second : kErrorType;
}

int Model::Calculation::GetPriority(const char c) const {
  static const std::map<char, int> kPriorities = {
      {'(', 0}, {'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}, {'%', 2},
      {'^', 3}, {'r', 4}, {'s', 4}, {'c', 4}, {'t', 4}, {'S', 4},
      {'C', 4}, {'T', 4}, {'n', 4}, {'l', 4}};
  auto it = kPriorities.find(c);
  if (it != kPriorities.end()) return it->second;
  throw std::invalid_argument("An incorrect argument entered the method");
}

void Model::Calculation::StackClearing(std::stack<char>& stack) {
  while (!stack.empty()) {
    postfix_ += stack.top();
    postfix_ += ' ';
    stack.pop();
  }
}

void Model::Calculation::OperatorHandling(std::stack<char>& stack,
                                          std::string::iterator& it) {
  while (!stack.empty() && GetPriority(stack.top()) >= GetPriority(*it)) {
    postfix_ += stack.top();
    postfix_ += ' ';
    stack.pop();
  }
  stack.push(*it);
}

void Model::Calculation::OperandOperation(std::string::iterator& it) {
  while (it != infix_.end() && GetSymbolType(*it) == kOperand) {
    postfix_ += *it;
    ++it;
  }
  --it;
  postfix_ += ' ';
}

void Model::Calculation::ClosingParenthesis(std::stack<char>& stack) {
  while (!stack.empty() && stack.top() != '(') {
    postfix_ += stack.top();
    postfix_ += ' ';
    stack.pop();
  }
  if (stack.empty()) {
    throw std::runtime_error(
        "Incorrect expression: unpaired closing parenthesis");
  }
  stack.pop();
}

void Model::Calculation::OpeningParenthesis(std::stack<char>& stack,
                                            std::string::iterator& it) {
  stack.push(*it);
  ++it;
  if (*it == '-') {
    postfix_ += *it;
  } else {
    --it;
  }
}

double Model::Calculation::PerformOperation(double operand, char oprt) {
  switch (oprt) {
    case 's':
      return std::sin(operand);
    case 'c':
      return std::cos(operand);
    case 't':
      return std::tan(operand);
    case 'S':
      return std::asin(operand);
    case 'C':
      return std::acos(operand);
    case 'T':
      return std::atan(operand);
    case 'n':
      return std::log(operand);
    case 'l':
      return std::log10(operand);
    case 'r':
      return std::sqrt(operand);
    default:
      throw std::runtime_error("Unknown operation");
  }
}

double Model::Calculation::PerformOperation(double first_operand,
                                            double second_operand, char oprt) {
  switch (oprt) {
    case '+':
      return first_operand + second_operand;
    case '-':
      return first_operand - second_operand;
    case '*':
      return first_operand * second_operand;
    case '/':
      return first_operand / second_operand;
    case '^':
      return std::pow(first_operand, second_operand);
    case '%':
      return std::fmod(first_operand, second_operand);
    default:
      throw std::runtime_error("Unknown operation");
  }
}

void Model::Calculation::LongOperation(std::stack<double>& operands,
                                       char oprt) {
  double second_operand = kDoubleNan, first_operand = kDoubleNan;
  second_operand = operands.top();
  operands.pop();
  first_operand = operands.top();
  operands.pop();
  operands.push(PerformOperation(first_operand, second_operand, oprt));
}

void Model::Calculation::ShortOperation(std::stack<double>& operands,
                                        char oprt) {
  double operand = kDoubleNan;
  operand = operands.top();
  operands.pop();
  operands.push(PerformOperation(operand, oprt));
}

bool Model::Calculation::IsOperand(const std::string& token) {
  bool is_number = isdigit(token[0]);
  if (!is_number && token[0] == '-' && token.size() > 1) {
    is_number = isdigit(token[1]);
  }
  return is_number;
}

double Model::Calculation::ActionForOperator(std::stack<double>& operands,
                                             char& oprt) {
  if (strchr("+-*/%^", oprt)) {
    LongOperation(operands, oprt);
  } else if (strchr("sScCtTlnr", oprt)) {
    ShortOperation(operands, oprt);
  } else {
    throw std::runtime_error("Invalid token in postfix");
  }
  return operands.top();
}

void Model::Calculation::SetInfix(const std::string& str) { infix_ = str; }

double Model::Calculation::Calculate(double x) {
  std::stack<double> operands;
  std::istringstream iss(postfix_);
  std::string token;
  while (iss >> token) {
    if (IsOperand(token)) {
      operands.push(s21::ParseStrToDouble(token));
    } else if (GetSymbolType(token[0]) == kOperator && token.size() == 1) {
      ActionForOperator(operands, token[0]);
    } else if (token[0] == 'x') {
      operands.push(x);
    } else if (token[0] == '-' && token[1] == 'x') {
      operands.push(-x);
    } else {
      throw std::runtime_error("Too few operands");
    }
  }
  return operands.top();
}

}  // namespace s21
