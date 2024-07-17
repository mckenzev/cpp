#ifndef SMART_CALC_SRC_VIEW_CALCULATION_H_
#define SMART_CALC_SRC_VIEW_CALCULATION_H_

#include <QStack>

#include "view.h"

namespace s21 {

class View::Calculation {
 public:
  /**
   * @brief Конструктор класса Calculation.
   * @param parent Указатель на родительский виджет.
   */
  explicit Calculation(View* parent);

  /**
   * @brief Обрабатывает входные данные.
   */
  void InputProcessing();

  /**
   * @brief Обновляет окно вывода.
   */
  void LabelUpdate();

  /**
   * @brief Удаляет открывающую скобку.
   */
  void DellOpenParentheses();

  /**
   * @brief Удаляет закрывающую скобку.
   */
  void DellClosedParentheses();

  /**
   * @brief Удаляет предыдущий символ.
   */
  void DellPrev();

  /**
   * @brief Постобработка данных.
   */
  void Postprocessing();

  /**
   * @brief Добавляет новый оператор в стек.
   * @param op Оператор, который нужно добавить.
   */
  void PushNew(QString op);

  QStack<QString> press_button_stack_;  ///< Стек для хранения нажатых кнопок.

 private:
  enum OperatorType {
    kMinus,           ///< Минус оператор.
    kBinaryOperator,  ///< Бинарный оператор.
    kMathFunction     ///< Математическая функция.
  };

  enum ExpressionType {
    kOperator,     ///< Оператор.
    kOperand,      ///< Операнд.
    kPoint,        ///< Точка.
    kParentheses,  ///< Скобки.
    kExponent      ///< Экспонента.
  };

  /**
   * @brief Обрабатывает ввод оператора.
   */
  void OperatorExpression();

  /**
   * @brief Обрабатывает ввод минуса.
   * @param op Оператор минус.
   */
  void MinusProcessing(const QString op);

  /**
   * @brief Проверяет, является ли выражение цифрой.
   * @param expression Проверяемое выражение.
   * @return true, если выражение является числом.
   */
  bool IsNum(const QString expression);

  /**
   * @brief Проверяет, является ли выражение оператором.
   * @param op Проверяемое выражение.
   * @return true, если это оператор.
   */
  bool IsOperator(const QString op);

  /**
   * @brief Проверяет, является ли выражение математической функцией.
   * @param op Проверяемое выражение.
   * @return true, если это математическая функция.
   */
  bool IsMathFunction(const QString op);

  /**
   * @brief Обрабатывает ввод бинарного оператора.
   * @param op Бинарный оператор.
   */
  void BinaryOpsProcessing(const QString op);

  /**
   * @brief Проверяет, является ли минус унарным.
   * @return true, если минус унарный.
   */
  bool IsUnaryMinus();

  /**
   * @brief Проверяет, является ли минус членом экспонентальнйо записи.
   * @return true, если минус - часть экспонентальной записи.
   */
  bool IsExponentMinus();

  /**
   * @brief Обрабатывает ввод математической функции.
   * @param op Математическая функция.
   */
  void MathFuncProcessing(const QString op);

  /**
   * @brief Обрабатывает ввод операнда.
   */
  void OperandExpression();

  /**
   * @brief Обрабатывает ввод цифры.
   * @param num Цифра.
   */
  void ProcessNum(QString num);

  /**
   * @brief Обрабатывает ввод символа 'x'.
   * @param op Символ 'x'.
   */
  void ProcessX(QString op);

  /**
   * @brief Проверяет, можно ли вписать новую цифру.
   * @return true, если ввод цифры допустим.
   */
  bool IsDigitAllowed();

  /**
   * @brief Обрабатывает ввод точки.
   */
  void PointExpression();

  /**
   * @brief Проверяет, можно ли добавить знак экспоненты выражению.
   * @return True ввод допустим.
   */
  bool IsExponentAllowed();

  /**
   * @brief Обрабатывает ввод знака экспоненты.
   */
  void ExponentExpression();
  /**
   * @brief Проверяет, можно ли добавить выражению точку.
   * @return true, если ввод точки допустим.
   */
  bool IsPointAllowed();

  /**
   * @brief Обрабатывает ввод скобки.
   */
  void ParenthesesExpression();
  /**
   * @brief Обрабатывает ввод открывающей скобки.
   */
  void OpenParenthesesProcessing();

  /**
   * @brief Обрабатывает ввод закрывающей скобки.
   */
  void ClosedParenthesesProcessing();

  /**
   * @brief Добавляет открывающую скобку.
   */
  void AddOpenParentheses();

  /**
   * @brief Добавляет закрывающую скобку.
   */
  void AddClosedParentheses();

  // Переменные
  int number_open_parentheses_;  ///< Переменная для подсчета открытых скобок
  int number_closed_parentheses_;  ///< Переменная для подсчета закрытых скобок
  View* parent_view_;  ///< Указатель на родительский виджет.
};

}  // namespace s21

#endif  // SMART_CALC_SRC_VIEW_CALCULATION_H_
