#include "controller.h"

#include <cmath>
#include <unordered_set>
#include <utility>

namespace s21 {

Controller::Controller(Model* model) : model_(model), x_value_(0.0) {}

std::vector<int>& Controller::GetMatrix(std::string& expression,
                                        const s21::GraphParams& params) {
  SetNewOriginal(expression);
  return model_->GetMatrix(params);
}

void Controller::ConvertToSimple(std::string& expression) {
  static const std::pair<std::string, std::string> kExpressionReplacements[] = {
      {"√", "r"},   {"asin", "S"}, {"acos", "C"}, {"atan", "T"},
      {"sin", "s"}, {"cos", "c"},  {"tan", "t"},  {"ln", "n"},
      {"log", "l"}, {"÷", "/"},    {",", "."},    {"-(-", "("}};
  static const int kNumExpressions =
      sizeof(kExpressionReplacements) / sizeof(kExpressionReplacements[0]);
  size_t pos_now = 0;
  size_t pos_was = 0;
  simple_expression_ = "(";

  while (pos_now != expression.length()) {
    for (int i = 0; i < kNumExpressions; ++i) {
      pos_was = pos_now;
      if (expression.find(kExpressionReplacements[i].first, pos_was) ==
          pos_was) {
        std::string replacement = kExpressionReplacements[i].second;
        InsertMultiplicationIfNeeded(replacement[0]);
        simple_expression_ += replacement;
        pos_now += kExpressionReplacements[i].first.length();
        break;
      }
    }
    if (pos_now == pos_was) {
      InsertMultiplicationIfNeeded(expression.at(pos_was));
      simple_expression_ += expression.at(pos_was);
      ++pos_now;
    }
  }
  simple_expression_ += ")*1";
}

void Controller::ExponentProcessing() {
  size_t pos = simple_expression_.find('e');

  if (pos == std::string::npos) {
    return;
  }

  size_t start = pos;

  while (start > 0 && (std::isdigit(simple_expression_[start - 1]) ||
                       simple_expression_[start - 1] == '.')) {
    --start;
  }
  simple_expression_.insert(start, "(");

  size_t end = pos + 2;

  if (simple_expression_[end] == '-') {
    ++end;
  }

  while (end < simple_expression_.size() &&
         std::isdigit(simple_expression_[end])) {
    ++end;
  }
  simple_expression_.insert(end, ")");

  ++pos;
  if (simple_expression_[pos + 1] == '-') {
    simple_expression_.replace(pos, 2, "*0.1^");
  } else {
    simple_expression_.replace(pos, 1, "*10^");
  }

  ExponentProcessing();
}

double Controller::GetResult(std::string& expression, double x) {
  SetNewOriginal(expression);
  if (std::isnan(x_value_) || (x != x_value_)) {
    x_value_ = x;
    model_->Calculate(x);
  }
  return model_->GetResult();
}

void Controller::SetNewOriginal(std::string& expression) {
  if (expression != original_expression_) {
    original_expression_ = expression;
    x_value_ = kDoubleNan;
    ConvertToSimple(expression);
    ExponentProcessing();
    model_->SetInfix(simple_expression_);
  }
}

void Controller::InsertMultiplicationIfNeeded(char ch) {
  char prev_ch = simple_expression_.back();
  if ((IsOperand(prev_ch) && IsMathFunction(ch)) ||
      (prev_ch == ')' && std::isdigit(ch))) {
    simple_expression_ += "*";
  }
}

bool Controller::IsOperand(char ch) {
  return (ch == 'x' || ch == ')' || std::isdigit(ch));
}

bool Controller::IsMathFunction(char ch) {
  static const std::unordered_set<char> kMathFunction = {
      'r', 'l', 'n', 'S', 's', 'C', 'c', 'T', 't', '(', 'x'};
  return kMathFunction.find(ch) != kMathFunction.end();
}

}  // namespace s21
