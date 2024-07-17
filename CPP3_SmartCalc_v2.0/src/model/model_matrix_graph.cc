#include "model_matrix_graph.h"

#include <cmath>

namespace s21 {

Model::MatrixGraph::MatrixGraph(const GraphParams& params)
    : params_(params), x_step_(0), y_step_(0) {}

void Model::MatrixGraph::SetStep() {
  x_step_ = std::abs(params_.x_max - params_.x_min) /
            (params_.w_graph * params_.scale_factor);
  y_step_ = std::abs(params_.y_max - params_.y_min) / (params_.h_graph);
}

std::vector<int> Model::MatrixGraph::CreateMatrix(Calculation* calculation) {
  std::vector<int> matrix(params_.w_graph * params_.scale_factor);
  double y;
  SetStep();
  unsigned int loop_limit = params_.w_graph * params_.scale_factor;
  for (unsigned int x = 0; x < loop_limit; ++x) {
    // результат в условных сантиметрах
    y = calculation->Calculate(params_.x_min + x * x_step_);
    // результат в пикселях
    y = std::round(y / y_step_);
    matrix[x] = y;
  }
  return matrix;
}

}  // namespace s21
