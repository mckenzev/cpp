#ifndef SMART_CALC_SRC_INCLUDE_UTILS_WITH_QT_H_
#define SMART_CALC_SRC_INCLUDE_UTILS_WITH_QT_H_

#include <QLineEdit>

namespace s21 {

/**
 * @brief Универсальный парсинг в double значения из QLineEdit. Переводя в
 * string вызывает другую перегрузку этой функции.
 *
 * @param str Указатель на QLineEdit*, из которого независимо от разделителя '.'
 * или ',' надо произвести успешный парсинг в double.
 * @return Преобразование значения в double.
 */
double ParseStrToDouble(QLineEdit* str);

}  // namespace s21

#endif
