#include "model.h"

#include "model_calculation.h"
#include "model_matrix_graph.h"

namespace s21 {

Model::Model() : result_(0), calc_(new Calculation), matrix_graph_(nullptr) {}

Model::~Model() {
  delete calc_;
  delete matrix_graph_;
}

void Model::Calculate(double x) { result_ = calc_->Calculate(x); }

double Model::GetResult() const { return result_; }

std::vector<int>& Model::GetMatrix(const GraphParams& params) {
  if (matrix_graph_ == nullptr) {
    matrix_graph_ = new MatrixGraph(params);
  }
  matrix_ = matrix_graph_->CreateMatrix(calc_);
  return matrix_;
}

void Model::SetInfix(const std::string& str) {
  calc_->SetInfix(str);
  calc_->InfixToPostfix();
}

}  // namespace s21
