#ifndef SMART_CALC_SRC_CONTROLLER_H_
#define SMART_CALC_SRC_CONTROLLER_H_

#include <string>

#include "../include/utils.h"
#include "../model/model.h"

namespace s21 {

/**
 * @brief Класс Controller действует как посредник между View и Model,
 * обрабатывая преобразование выражений и управление состоянием.
 */
class Controller {
 public:
  /**
   *  @brief Конструктор, инициализирующий Controller с обязательным указателем
   * на Model.
   */
  explicit Controller(Model* model_);

  /**
   * @brief Вычисляет результат данного выражения для указанного значения x.
   * @param expression математическое выражение для вычисления.
   * @param x значение для подстановки вместо 'x' в выражении.
   * @return результат вычисления.
   */
  double GetResult(std::string& expression, double x);

  /**
   * @brief Возвращает матричное представление данного выражения на основе
   * параметров графика.
   * @param expression математическое выражение для вычислений.
   * @param params параметры графика.
   * @return вектор, представляющий матрицу выражения.
   */
  std::vector<int>& GetMatrix(std::string& expression,
                              const s21::GraphParams& params);

 private:
  /**
   * @brief Преобразует математическое выражение из View в упрощенный формат для
   * Model.
   * @param expression выражение для преобразования.
   */
  void ConvertToSimple(std::string& expression);

  /**
   * @brief Передает в Model упрощенное выражение и обновляет
   * original_expression_.
   * @param expression новое выражение для передачи в Model.
   */
  void SetNewOriginal(std::string& expression);

  /**
   * @brief Вставляет символ умножения в упрощенное выражение, если это
   * необходимо по контексту.
   * @param ch текущий символ, обрабатываемый в выражении.
   */
  void InsertMultiplicationIfNeeded(char ch);

  /**
   * @brief Проверяет, является ли данный символ математической функцией.
   * @param ch символ для проверки.
   * @return true, если символ является математической функцией, иначе false.
   */
  bool IsMathFunction(char ch);

  /**
   * @brief Проверяет, является ли данный символ операндом.
   * @param ch символ для проверки.
   * @return true, если символ является операндом, иначе false.
   */
  bool IsOperand(char ch);

  /**
   * @brief Обрабатывает эксонентальную запись, переводя ее в умножение на 10 в
   * степени.
   */
  void ExponentProcessing();

  Model* model_;  ///< Указатель на модель, используемую для вычислений.
  double x_value_;  ///< Текущее значение x, используемое в вычислениях.
  std::string
      original_expression_;  ///< Последнее переданное в Model выражение.
  std::string simple_expression_;  ///< Упрощенная версия исходного выражения.
};
}  // namespace s21
#endif  // SMART_CALC_SRC_CONTROLLER_H_
