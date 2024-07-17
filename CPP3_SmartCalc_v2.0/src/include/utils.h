#ifndef SMART_CALC_SRC_INCLUDE_UTILS_H_
#define SMART_CALC_SRC_INCLUDE_UTILS_H_

#include <limits>
#include <string>

namespace s21 {

/**
 * @brief Параметры для графика
 *
 * @param x_min        Минимальное значение по оси X
 * @param x_max        Максимальное значение по оси X
 * @param y_min        Минимальное значение по оси Y
 * @param y_max        Максимальное значение по оси Y
 * @param h_graph      Высота графика
 * @param w_graph      Ширина графика
 * @param scale_factor Масштабный коэффициент (от 1 до 300)
 */
struct GraphParams {
  double x_min = 0.0;
  double x_max = 0.0;
  double y_min = 0.0;
  double y_max = 0.0;
  unsigned int h_graph = 0u;
  unsigned int w_graph = 0u;
  unsigned int scale_factor = 1u;
};

/**
 * @param kDoubleNan Nan значение для типа double.
 */
static constexpr double kDoubleNan = std::numeric_limits<double>::quiet_NaN();

/**
 * @brief Независимый от локали парсинг в double. Перегрузка для string.
 *
 * @param str Ссылка на строку типа string.
 * @return Преобразование значения в double.
 */
double ParseStrToDouble(const std::string& str);

}  // namespace s21
#endif  // SMART_CALC_SRC_INCLUDE_UTILS_H_
