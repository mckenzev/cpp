#ifndef SMARTCALC_SRC_MODEL_MATRIX_GRAPH_H_
#define SMARTCALC_SRC_MODEL_MATRIX_GRAPH_H_

#include <vector>

#include "model.h"
#include "model_calculation.h"

namespace s21 {
class Model::MatrixGraph {
 public:
  /**
   * @brief Конструктор класса Model::MatrixGraph.
   * @param params ссылка на параметры окна отрисовки графика.
   */
  explicit MatrixGraph(const GraphParams& params);

  /**
   * @brief Производит расчет для отрисовки графика.
   * @param calculation указатель на обьект класса, на основе которого будут
   * произведены расчеты.
   * @return вектор, который представляет собой матрицу, где индекс отвечает за
   * ось `x`, а значение по индексу - ось `y`
   */
  std::vector<int> CreateMatrix(Calculation* calculation);

 private:
  /**
   * @brief Устанавливает размер шага по осям `x` и `y` на основе params_
   */
  void SetStep();

  const GraphParams& params_;  /// < Параметры окна для отрисовки графика
  long double x_step_;  /// < Шаг по оси x
  long double y_step_;  /// < Шаг по оси y
};
}  // namespace s21

#endif  // SMARTCALC_SRC_MODEL_MATRIX_GRAPH_H_
