#ifndef SMARTCALC_SRC_MODEL_H_
#define SMARTCALC_SRC_MODEL_H_

#include <string>
#include <vector>

#include "../include/utils.h"

namespace s21 {

class Model {
 public:
  Model();
  ~Model();

  /**
   * @brief Производит математические вычисления по выражению calc_->infix_.
   * Результат вычисления передается переменной result_
   *
   * @param x Значение 'x' на случай, если было передано уравнение.
   * @return Результат хранится в переменной result_. Для получения результата
   * используется метод GetResult()
   */
  void Calculate(double x);

  /**
   * @brief Метод передает в класс Calculation инфиксное сокращенное выражение,
   * которое преобразуется в постфиксную форму. Метод применяется перед
   * использованием методов Calculate(double x) и GetMatrix().
   *
   * @param str Сокращенное математическое выражение.
   */
  void SetInfix(const std::string& str);

  /**
   * @brief Метод для доступа к приватному члену класса result_
   *
   * @return result_ результат вычислений метода Calculate(double x)
   */
  double GetResult() const;

  /**
   * @brief Метод для получения матрицы с точками для отрисовки графика функции,
   * переданной методом SetInfix(). Индекс - значение по оси X, значение по
   * индексу - значение по оси Y. Размер массива равен произведению длины поля
   * для отрисовки и коэффициенту масштабирования (params.w_graph *
   * params.scale_factor). Для отрисовки графика по этому массиву следует делить
   * индекс на params.scale_factor, что поспособствует повышению точности в
   * params.scale_factor раз.
   *
   * @param params Структура с параметрами поля для отрисовки графика.
   * @return Матрица с информацией о точках для графика функции. Индекс -
   * значение по Х, значение по индексу - значение по Y.
   */
  std::vector<int>& GetMatrix(const GraphParams& params);

 private:
  class Calculation;
  class MatrixGraph;

  double result_;
  std::vector<int> matrix_;
  Calculation* calc_;
  MatrixGraph* matrix_graph_;
};

}  // namespace s21

#endif  // SMARTCALC_SRC_MODEL_H_
