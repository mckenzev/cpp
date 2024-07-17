#include "view_calculation.h"

#include <QMap>

#include "ui_view.h"

namespace s21 {

View::Calculation::Calculation(View* parent)
    : number_open_parentheses_(0),
      number_closed_parentheses_(0),
      parent_view_(parent) {}

void View::Calculation::LabelUpdate() {
  auto result_show = parent_view_->ui_->result_show_;
  auto func_label = parent_view_->ui_->func_label_;
  auto text_expression = parent_view_->text_expression_;
  if (parent_view_->text_expression_.length()) {
    result_show->setText(text_expression);
    func_label->setText(text_expression);
  } else {
    result_show->setText("0");
    func_label->setText("0");
  }
}

void View::Calculation::InputProcessing() {
  static const QMap<QString, ExpressionType> kExpressions{
      {"+", kOperator},    {"-", kOperator},    {"*", kOperator},
      {"÷", kOperator},    {"^", kOperator},    {"%", kOperator},
      {"√", kOperator},    {"sin", kOperator},  {"cos", kOperator},
      {"tan", kOperator},  {"asin", kOperator}, {"acos", kOperator},
      {"atan", kOperator}, {"ln", kOperator},   {"log", kOperator},
      {"x", kOperand},     {"1", kOperand},     {"2", kOperand},
      {"3", kOperand},     {"4", kOperand},     {"5", kOperand},
      {"6", kOperand},     {"7", kOperand},     {"8", kOperand},
      {"9", kOperand},     {"0", kOperand},     {",", kPoint},
      {"(", kParentheses}, {")", kParentheses}, {"e", kExponent}};
  auto it = kExpressions.find(press_button_stack_.top());
  if (it != kExpressions.end()) {
    switch (it.value()) {
      case kOperator:
        OperatorExpression();
        break;
      case kOperand:
        OperandExpression();
        break;
      case kPoint:
        PointExpression();
        break;
      case kExponent:
        ExponentExpression();
        break;
      case kParentheses:
        ParenthesesExpression();
        break;
    }
  } else {
    throw std::runtime_error("Unknown expression");
  }
}

void View::Calculation::OperatorExpression() {
  static const QMap<QString, OperatorType> kOperators = {
      {"-", kMinus},           {"+", kBinaryOperator},  {"*", kBinaryOperator},
      {"÷", kBinaryOperator},  {"^", kBinaryOperator},  {"%", kBinaryOperator},
      {"√", kMathFunction},    {"sin", kMathFunction},  {"cos", kMathFunction},
      {"tan", kMathFunction},  {"asin", kMathFunction}, {"acos", kMathFunction},
      {"atan", kMathFunction}, {"ln", kMathFunction},   {"log", kMathFunction}};
  QString op = press_button_stack_.pop();
  const auto operator_type = kOperators.value(op);
  switch (operator_type) {
    case kMinus:
      MinusProcessing(op);
      break;
    case kBinaryOperator:
      BinaryOpsProcessing(op);
      break;
    case kMathFunction:
      MathFuncProcessing(op);
      break;
  }
}

void View::Calculation::MinusProcessing(const QString op) {
  if (!press_button_stack_.empty()) {
    auto top_symbol = press_button_stack_.top();
    if (top_symbol == "," || IsOperator(top_symbol)) {
      DellPrev();
    }
  }
  PushNew(op);
  LabelUpdate();
}

void View::Calculation::BinaryOpsProcessing(const QString op) {
  if (!press_button_stack_.empty()) {
    auto top_symbol = press_button_stack_.top();
    if (IsNum(top_symbol) || top_symbol == "x" || top_symbol == ")") {
      PushNew(op);
    } else if (top_symbol == "," ||
               (IsOperator(top_symbol) && !IsUnaryMinus())) {
      DellPrev();
      PushNew(op);
    }
    LabelUpdate();
  }
}

void View::Calculation::PushNew(QString op) {
  parent_view_->text_expression_ += op;
  press_button_stack_.push(op);
}

void View::Calculation::DellPrev() {
  parent_view_->text_expression_.chop(press_button_stack_.top().length());
  press_button_stack_.pop();
}

bool View::Calculation::IsUnaryMinus() {
  QString buffer = press_button_stack_.pop();
  bool result = true;
  if (!press_button_stack_.empty()) {
    auto top_symbol = press_button_stack_.top();
    result = (top_symbol == "(" || top_symbol == "e");
  }
  press_button_stack_.push(buffer);
  return result;
}

bool View::Calculation::IsExponentMinus() {
  QString buffer = press_button_stack_.pop();
  bool result = false;
  if (!press_button_stack_.empty()) {
    auto top_symbol = press_button_stack_.top();
    result = (top_symbol == "e");
  }
  press_button_stack_.push(buffer);
  return result;
}

bool View::Calculation::IsNum(const QString expression) {
  static const QVector<QString> kNumbers = {"1", "2", "3", "4", "5",
                                            "6", "7", "8", "9", "0"};
  return kNumbers.contains(expression);
}

bool View::Calculation::IsOperator(const QString op) {
  static const QVector<QString> kOperators = {"-", "+", "*", "%", "÷", "^"};
  return kOperators.contains(op);
}

bool View::Calculation::IsMathFunction(const QString op) {
  static const QVector<QString> kFunctions = {"sin",  "cos",  "tan", "asin",
                                              "acos", "atan", "ln",  "log"};
  return kFunctions.contains(op);
}

void View::Calculation::MathFuncProcessing(const QString op) {
  if (!press_button_stack_.empty()) {
    if (press_button_stack_.top() == "e") {
      return;
    }
    if (press_button_stack_.top() == "-" && IsExponentMinus()) {
      return;
    }
    if (press_button_stack_.top() == ",") {
      DellPrev();
    }
  }
  PushNew(op);
  AddOpenParentheses();
}

void View::Calculation::OperandExpression() {
  QString prev_expression = press_button_stack_.pop();
  if (IsNum(prev_expression)) {
    ProcessNum(prev_expression);
  } else {
    ProcessX(prev_expression);
  }
}

void View::Calculation::ProcessNum(QString number) {
  if (IsDigitAllowed()) {
    PushNew(number);
  }
}

bool View::Calculation::IsDigitAllowed() {
  // если стек не пуст, можем проверить последний элемент стека. Если это 'x',
  // цифру добавить нельзя
  if (!press_button_stack_.empty() && press_button_stack_.top() == "x") {
    return false;
  }
  // если стек пуст или последний символ не ноль, новую цифру можно добавить
  if (press_button_stack_.empty() || press_button_stack_.top() != "0") {
    return true;
  }
  // буфер создается для вывода верхнего элемента из
  // стека и анализа элемента, стоящего за ним
  QString buffer = press_button_stack_.pop();
  // если следующий элемент отсутствует, значит
  // ноль был единственной цифрой числа, значит
  // нельзя добавить новую цифру
  if (press_button_stack_.empty()) {
    press_button_stack_.push(buffer);
    return false;
  }
  // если перед нулем стоит оператор или скобка, значит ноль был
  // единственной цифрой числа, значит нелья добавить новую цифру
  if (IsOperator(press_button_stack_.top()) ||
      press_button_stack_.top() == "(") {
    press_button_stack_.push(buffer);
    return false;
  }
  press_button_stack_.push(buffer);
  // во всех остальных случаях цифру можно добавить
  return true;
}

void View::Calculation::ProcessX(QString op) {
  bool can_push = true;
  if (!press_button_stack_.empty()) {
    if (press_button_stack_.top() == "e") {
      return;
    } else if (press_button_stack_.top() == ",") {
      DellPrev();
    } else if (!IsDigitAllowed()) {
      can_push = false;
    }
  }
  if (can_push) {
    PushNew(op);
  }
}

bool View::Calculation::IsPointAllowed() {
  if (press_button_stack_.empty()) {
    PushNew("0");
    return true;
  }

  bool result = false;
  // точку можно ставить только после цифры
  if (IsNum(press_button_stack_.top())) {
    bool has_point = false;
    bool has_e = false;

    // Перебираем элементы стека пока не встретим нецифру или не опустеет стек
    QStack<QString> buffer;
    while (!press_button_stack_.empty() &&
           (buffer.empty() || IsNum(buffer.top()))) {
      buffer.push(press_button_stack_.pop());
    }

    if (!press_button_stack_.empty()) {
      if (press_button_stack_.top() == 'e') {
        has_e = true;
      }
    }
    if (buffer.top() == ',') {
      has_point = true;
    } else if (buffer.top() == 'e') {
      has_e = true;
    }
    // Возврат в изначальный стек значений из буфера
    while (!buffer.empty()) {
      press_button_stack_.push(buffer.pop());
    }
    result = (!has_e && !has_point);
  }

  return result;
}

void View::Calculation::PointExpression() {
  QString point = press_button_stack_.pop();
  if (IsPointAllowed()) {
    PushNew(point);
  }
}

bool View::Calculation::IsExponentAllowed() {
  if (press_button_stack_.empty()) {
    PushNew("0");
    return true;
  }

  bool result = false;
  if (IsNum(press_button_stack_.top())) {
    QStack<QString> buffer;
    bool has_e = false;

    while (!press_button_stack_.empty() &&
           (buffer.empty() || IsNum(buffer.top()))) {
      buffer.push(press_button_stack_.pop());
    }

    if (!press_button_stack_.empty() && press_button_stack_.top() == 'e') {
      has_e = true;
    }

    if (buffer.top() == 'e') {
      has_e = true;
    }

    while (!buffer.empty()) {
      press_button_stack_.push(buffer.pop());
    }
    result = !has_e;
  }
  return result;
}

void View::Calculation::ExponentExpression() {
  QString exponent = press_button_stack_.pop();
  if (IsExponentAllowed()) {
    PushNew(exponent);
  }
}

void View::Calculation::ParenthesesExpression() {
  QString op = press_button_stack_.pop();
  if (op == "(") {
    OpenParenthesesProcessing();
  } else if (op == ")") {
    ClosedParenthesesProcessing();
  }
}

void View::Calculation::OpenParenthesesProcessing() {
  if (!press_button_stack_.empty() && press_button_stack_.top() == ",") {
    DellPrev();
  }
  if (press_button_stack_.empty() ||
      (press_button_stack_.top() != ")" && press_button_stack_.top() != "e")) {
    AddOpenParentheses();
  }
}

void View::Calculation::ClosedParenthesesProcessing() {
  if (!press_button_stack_.empty() && press_button_stack_.top() == "e") {
    return;
  }
  int difference = number_open_parentheses_ - number_closed_parentheses_;
  if (!press_button_stack_.empty() && difference > 0) {
    if (press_button_stack_.top() == ",") {
      DellPrev();
    }
    if (press_button_stack_.top() != "(" &&
        !IsOperator(press_button_stack_.top())) {
      AddClosedParentheses();
    }
  }
}

void View::Calculation::AddOpenParentheses() {
  PushNew("(");
  ++number_open_parentheses_;
}

void View::Calculation::AddClosedParentheses() {
  PushNew(")");
  ++number_closed_parentheses_;
}

void View::Calculation::DellOpenParentheses() {
  DellPrev();
  if (!press_button_stack_.empty() &&
      IsMathFunction(press_button_stack_.top())) {
    DellPrev();
  }
  --number_open_parentheses_;
}

void View::Calculation::DellClosedParentheses() {
  DellPrev();
  --number_closed_parentheses_;
}

void View::Calculation::Postprocessing() {
  int number_difference = number_open_parentheses_ - number_closed_parentheses_;
  while (number_difference) {
    AddClosedParentheses();
    number_difference--;
  }
  // т.к. обьект класса не уничтожается и может еще множество раз
  // переиспользоваться, счетчики обнуляются
  number_open_parentheses_ = 0;
  number_closed_parentheses_ = 0;
}
}  // namespace s21
