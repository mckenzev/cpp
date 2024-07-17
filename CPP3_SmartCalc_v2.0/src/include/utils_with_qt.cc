#include "utils_with_qt.h"

#include <QString>

#include "utils.h"

namespace s21 {

double ParseStrToDouble(QLineEdit* str) {
  QString qstr = str->text();
  std::string tmp = qstr.toStdString();
  return ParseStrToDouble(tmp);
}
}  // namespace s21
