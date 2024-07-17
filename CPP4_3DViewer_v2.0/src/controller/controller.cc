#ifndef VIEWER_V_2_0_SRC_CONTROLLER_CONTROLLER_CC
#define VIEWER_V_2_0_SRC_CONTROLLER_CONTROLLER_CC

#include "controller.h"

namespace s21 {

void Controller::Rotate(const double& step, const Axis& axis) {
  model_.Rotate(step, axis);
}

void Controller::Move(const double& step, const Axis& axis) {
  model_.Move(step, axis);
}

void Controller::Normalization() { model_.Normalization(); }

void Controller::Scale(double value) { model_.Scale(value); }

bool Controller::Parse() { return model_.Parse(); }

void Controller::FillingCoords() { model_.FillingCoords(); }

}  // namespace s21
#endif  // VIEWER_V_2_0_SRC_CONTROLLER_CONTROLLER_CC
