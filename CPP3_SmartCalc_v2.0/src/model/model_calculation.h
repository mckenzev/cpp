#ifndef SMARTCALC_SRC_MODEL_CALCULATION_H_
#define SMARTCALC_SRC_MODEL_CALCULATION_H_

#include <stack>
#include <string>

#include "model.h"

namespace s21 {
class Model::Calculation {
 public:
  /**
   * @brief Перечисление операций, поддерживаемых PerformOperation().
   */
  enum Operation {
    kSum = 1,
    kSub = 2,
    kMul = 3,
    kDiv = 4,
    kMod = 5,
    kPow = 6,
    kSin = 7,
    kCos = 8,
    kTan = 9,
    kAsin = 10,
    kAcos = 11,
    kAtan = 12,
    kSqrt = 13,
    kLn = 14,
    kLog = 15
  };

  /**
   * @brief Перечисление типов символов для метода IsOperator().
   */
  enum SymbolType {
    kOperator = 1,
    kOperand = 2,
    kOpenParenthesis = 3,
    kCloseParenthesis = 4,
    kErrorType = 5
  };

  /**
   * @brief Преобразует инфиксное выражение в постфиксное. Вызывается после
   * SetInfix().
   */
  void InfixToPostfix();

  /**
   * @brief Устанавливает инфиксное выражение.
   * @param str Сокращенное математическое выражение в инфиксной форме.
   */
  void SetInfix(const std::string& str);

  /**
   * @brief Вычисляет значение выражения в постфиксной форме.
   * @param x Значение переменной 'x', если оно используется в выражении.
   * @return Результат вычисления.
   */
  double Calculate(double x);

 private:
  std::string infix_;  /// < Хранит инфиксное выражение.
  std::string postfix_;  /// < Хранит постфиксное выражение.

  /**
   * @brief Проверяет, к какому типу относится символ.
   * @param c Символ для проверки.
   * @return Тип символа.
   */
  SymbolType GetSymbolType(const char c) const;

  /**
   * @brief Возвращает приоритет оператора.
   * @param c Символ оператора.
   * @return Приоритет оператора.
   */
  int GetPriority(const char c) const;

  /**
   * @brief Очищает стек операторов, добавляя их в постфиксное выражение.
   * @param stack Стек операторов.
   */
  void StackClearing(std::stack<char>& stack);

  /**
   * @brief Обрабатывает оператор в инфиксном выражении.
   * @param stack Стек операторов.
   * @param it Итератор по инфиксному выражению.
   */
  void OperatorHandling(std::stack<char>& stack, std::string::iterator& it);

  /**
   * @brief Обрабатывает операнд в инфиксном выражении.
   * @param it Итератор по инфиксному выражению.
   */
  void OperandOperation(std::string::iterator& it);

  /**
   * @brief Обрабатывает закрывающую скобку в инфиксном выражении.
   * @param stc Стек операторов.
   */
  void ClosingParenthesis(std::stack<char>& stack);

  /**
   * @brief Обрабатывает открывающую скобку в инфиксном выражении.
   * @param stc Стек операторов.
   * @param it Итератор по инфиксному выражению.
   */
  void OpeningParenthesis(std::stack<char>& stack, std::string::iterator& it);

  /**
   * @brief Выполняет операцию с одним операндом.
   * @param operand Операнд.
   * @param oprt Оператор.
   * @return Результат операции.
   */
  double PerformOperation(double operand, char oprt);

  /**
   * @brief Выполняет операцию с двумя операндами.
   * @param first_operand Первый операнд.
   * @param second_operand Второй операнд.
   * @param oprt Оператор.
   * @return Результат операции.
   */
  double PerformOperation(double first_operand, double second_operand,
                          char oprt);

  /**
   * @brief Обрабатывает длинные операции (например, +, -, *, /).
   * @param operands Стек операндов.
   * @param oprt Оператор.
   */
  void LongOperation(std::stack<double>& operands, char oprt);

  /**
   * @brief Обрабатывает короткие операции (например, sin, cos).
   * @param operands Стек операндов.
   * @param oprt Оператор.
   */
  void ShortOperation(std::stack<double>& operands, char oprt);

  /**
   * @brief Проверяет, является ли токен операндом.
   * @param token Токен для проверки.
   * @return true, если токен является операндом.
   */
  bool IsOperand(const std::string& token);

  /**
   * @brief Выполняет операцию с операндом.
   * @param operands Стек операндов.
   * @param oprt Оператор.
   * @return Результат операции.
   */
  double ActionForOperator(std::stack<double>& operands, char& oprt);
};
}  // namespace s21

#endif  // SMARTCALC_SRC_MODEL_CALCULATION_H_
