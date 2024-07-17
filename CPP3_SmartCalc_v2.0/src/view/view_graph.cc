#include "view_graph.h"

#include <algorithm>
#include <cmath>

#include "../include/utils_with_qt.h"
#include "ui_view.h"

namespace s21 {

View::Graph::Graph(View* parent)
    : parent_view_(parent),
      initialized_(false),
      graphics_view_(nullptr),
      x_step_(0),
      y_step_(0),
      x_middle_(0),
      y_middle_(0),
      scene_(nullptr) {}

View::Graph::~Graph() { delete scene_; }

void View::Graph::SetMiddle() {
  x_middle_ = -params_.x_min * x_step_;
  y_middle_ = params_.y_max * y_step_;
}

void View::Graph::SetSteps() {
  x_step_ = params_.w_graph / (params_.x_max - params_.x_min);
  y_step_ = params_.h_graph / (params_.y_max - params_.y_min);
}

void View::Graph::InitImmutableValues() {
  // Определение поля для отрисовки графика
  graphics_view_ = parent_view_->ui_->graphics_view_;

  // Создание сцены
  scene_ = new QGraphicsScene(graphics_view_);

  // Ширина и высота поля для отрисовки
  params_.w_graph = graphics_view_->width();
  params_.h_graph = graphics_view_->height();
}

void View::Graph::InitValues() {
  // Минимальные и максимальные значения осей
  params_.x_max = s21::ParseStrToDouble(parent_view_->ui_->line_edit_max_x_);
  params_.x_min = s21::ParseStrToDouble(parent_view_->ui_->line_edit_min_x_);
  params_.y_max = s21::ParseStrToDouble(parent_view_->ui_->line_edit_max_y_);
  params_.y_min = s21::ParseStrToDouble(parent_view_->ui_->line_edit_min_y_);

  // Коэффициент масштабирования
  InitScaleFactor();

  // Точки пересечения осей Ох и Оу
  SetSteps();
  SetMiddle();
}

void View::Graph::InitScaleFactor() {
  // Коэффициент kFactor отвечает за количество расчетов(для повышения точности)
  constexpr unsigned int kFactor = 2u;

  // Ограничение для коэффициента маштабирования(во избежание избытка
  // перерасчетов и просадки ОЗУ)
  constexpr unsigned int kMaxScaleFactor = 300u;

  // Разница между максимальным и минимальным значениями х
  unsigned int x_range = params_.x_max - params_.x_min;

  // Если разница больше фактора, выполняется расчет scale_factor(иначе он равен
  // 1u по дефолт значению)
  if (x_range > kFactor) {
    params_.scale_factor = x_range / kFactor;
  }

  // Ограничиваем scale_factor максимальным значением для оптимизации
  if (params_.scale_factor > kMaxScaleFactor) {
    params_.scale_factor = kMaxScaleFactor;
  }
}

void View::Graph::InitSetting() {
  graphics_view_->setScene(scene_);
  scene_->setSceneRect(0, 0, graphics_view_->width(), graphics_view_->height());

  // Убирает на сцене ползунок для смещения графика
  graphics_view_->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  graphics_view_->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

void View::Graph::InitAxis() {
  QPen axis(Qt::black);
  DrawAxisX(axis);
  DrawAxisY(axis);
}

void View::Graph::DrawAxisX(const QPen& axis) {
  if ((y_middle_ <= params_.w_graph) && (y_middle_ >= 0)) {
    scene_->addLine(0, y_middle_, params_.w_graph, y_middle_, axis);
    DrawStepsX(axis);
  }
}

void View::Graph::DrawStepsX(const QPen& axis) {
  if (x_step_ > 1) {
    int pos_first_step = x_middle_ + static_cast<int>(params_.x_min) * x_step_;
    unsigned int loop_limit = params_.w_graph / static_cast<int>(x_step_) + 2;
    for (unsigned int i = 0; i < loop_limit; ++i) {
      int pos_x = pos_first_step + x_step_ * i;
      scene_->addLine(pos_x, y_middle_ - 1, pos_x, y_middle_ + 1, axis);
    }
  }
}

void View::Graph::DrawAxisY(const QPen& axis) {
  if ((x_middle_ <= params_.h_graph) && (x_middle_ >= 0)) {
    scene_->addLine(x_middle_, 0, x_middle_, params_.h_graph, axis);
    DrawStepsY(axis);
  }
}

void View::Graph::DrawStepsY(const QPen& axis) {
  if (y_step_ > 1) {
    int pos_first_step = y_middle_ - static_cast<int>(params_.y_max) * y_step_;
    unsigned int loop_limit = params_.h_graph / static_cast<int>(y_step_) + 2;
    for (unsigned int i = 0; i < loop_limit; ++i) {
      int pos_y = pos_first_step + y_step_ * i;
      scene_->addLine(x_middle_ - 1, pos_y, x_middle_ + 1, pos_y, axis);
    }
  }
}

bool View::Graph::IsNormalPoint(qreal y) {
  return ((y > params_.h_graph * -0.5) && (y < params_.h_graph * 1.5) &&
          !std::isinf(y) && !std::isnan(y));
}

void View::Graph::PrintGraph() {
  QPen pen(Qt::red);
  QPointF prev_point;
  bool has_prev_point = false;

  for (unsigned int x = 0; x < params_.w_graph * params_.scale_factor; ++x) {
    qreal y = y_middle_ - matrix_[x];
    qreal scaled_x = x / params_.scale_factor;
    QPointF current_point(scaled_x, y);

    if (has_prev_point) {
      if (IsNormalPoint(prev_point.y()) && IsNormalPoint(current_point.y())) {
        scene_->addLine(prev_point.x(), prev_point.y(), current_point.x(),
                        current_point.y(), pen);
      }
    } else {
      has_prev_point = true;
    }
    prev_point = current_point;
  }

  ClearVector(matrix_);
}

template <typename T>
void View::Graph::ClearVector(T& vec) {
  T tmp_vec;
  tmp_vec.swap(vec);
}

void View::Graph::Show() {
  scene_->clear();
  InitAxis();
  PrintGraph();
}

void View::Graph::Initialization() {
  if (!initialized_) {
    InitImmutableValues();
    InitSetting();
    initialized_ = true;
  }
  InitValues();
}

const GraphParams& View::Graph::GetParams() const { return params_; }

void View::Graph::PassMatrix(std::vector<int>& matrix) {
  matrix_.resize(matrix.size());
  std::transform(matrix.begin(), matrix.end(), matrix_.begin(),
                 [](int value) { return static_cast<qreal>(value); });

  ClearVector(matrix);
}

}  // namespace s21
