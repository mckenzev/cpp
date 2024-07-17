#ifndef VIEWER_V_2_0_SRC_CONTROLLER_CONTROLLER_H
#define VIEWER_V_2_0_SRC_CONTROLLER_CONTROLLER_H

#include <string>
#include <vector>

#include "../model/model.h"

namespace s21 {
using my_vector = std::vector<double>&;

class Controller {
 public:
  Controller(my_vector coordinates, my_vector vertices, std::string& filename)
      : model_(coordinates, vertices, filename) {}
  bool Parse();
  void Normalization();
  void Scale(double value);
  void Rotate(const double& step, const Axis& axis);
  void Move(const double& step, const Axis& axis);
  void FillingCoords();

 private:
  Model model_;
};
}  // namespace s21

#endif  // VIEWER_V_2_0_SRC_CONTROLLER_CONTROLLER_H
