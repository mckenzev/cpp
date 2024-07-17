#include "view.h"

#include <QMap>
#include <QRegularExpression>
#include <QRegularExpressionValidator>
#include <cmath>
#include <string>

#include "../include/utils_with_qt.h"
#include "ui_view.h"
#include "view_calculation.h"
#include "view_graph.h"

namespace s21 {

View::View(QWidget* parent, Controller* controller)
    : QMainWindow(parent),
      ui_(new Ui::View),
      controller_(controller),
      calculation_(new Calculation(this)),
      graph_(new Graph(this)),
      buttons_(nullptr) {
  ui_->setupUi(this);
  StartSetting();
  AllConnects();
}

View::~View() {
  delete buttons_;
  delete calculation_;
  delete graph_;
  delete ui_;
}

void View::PressButton(int id) {
  QPushButton* button_ = static_cast<QPushButton*>(buttons_->button(id));
  QString text_button = button_->text();
  calculation_->press_button_stack_.push(text_button);
  calculation_->InputProcessing();
  calculation_->LabelUpdate();
}

void View::PressBackspace() {
  auto press_button_stack = calculation_->press_button_stack_;
  if (!press_button_stack.empty()) {
    QString del_str = calculation_->press_button_stack_.top();
    if (del_str == ")") {
      calculation_->DellClosedParentheses();
    } else if (del_str == "(") {
      calculation_->DellOpenParentheses();
    } else {
      calculation_->DellPrev();
    }
  }
  calculation_->LabelUpdate();
}

void View::CleanTextExpression() {
  text_expression_.clear();
  calculation_->press_button_stack_.clear();
  calculation_->LabelUpdate();
}

void View::ShowGraph() {
  if (IncorrectExpression()) {
    ui_->error_label_graph_->setText("Не корректное выражение!");
    ui_->error_label_graph_->show();
  } else {
    if (text_expression_.isEmpty()) ui_->push_button_num_0_->click();
    if (IsGraphRangeValid()) {
      ui_->error_label_graph_->hide();
      calculation_->Postprocessing();
      calculation_->LabelUpdate();
      std::string expression = text_expression_.toStdString();
      graph_->Initialization();
      std::vector<int> matrix =
          controller_->GetMatrix(expression, graph_->GetParams());
      graph_->PassMatrix(matrix);
      graph_->Show();
    } else {
      ui_->error_label_graph_->setText(
          "Минимальное значение x или y\nбольше максимального!");
      ui_->error_label_graph_->show();
    }
  }
}

void View::AllConnects() {
  CreateQButtonGroup();
  connect(buttons_, SIGNAL(idClicked(int)), this, SLOT(PressButton(int)));
  connect(ui_->push_button_widget_, SIGNAL(clicked()), this,
          SLOT(ResizeMainWindow()));
  connect(ui_->push_button_clear_, SIGNAL(clicked()), this,
          SLOT(CleanTextExpression()));
  connect(ui_->push_button_backspace_, SIGNAL(clicked()), this,
          SLOT(PressBackspace()));
  connect(ui_->push_button_graph_, SIGNAL(clicked()), this, SLOT(ShowGraph()));
  connect(ui_->push_button_equal_, SIGNAL(clicked()), this, SLOT(Calculate()));
}

void View::CreateQButtonGroup() {
  buttons_ = new QButtonGroup(this);
  const QVector<QPushButton*> kAllButtons = {
      ui_->push_button_num_0_,
      ui_->push_button_num_1_,
      ui_->push_button_num_2_,
      ui_->push_button_num_3_,
      ui_->push_button_num_4_,
      ui_->push_button_num_5_,
      ui_->push_button_num_6_,
      ui_->push_button_num_7_,
      ui_->push_button_num_8_,
      ui_->push_button_num_9_,
      ui_->push_button_point_,
      ui_->push_button_plus_,
      ui_->push_button_minus_,
      ui_->push_button_mul_,
      ui_->push_button_div_,
      ui_->push_button_left_parenthesis_,
      ui_->push_button_right_parenthesis_,
      ui_->push_button_mod_,
      ui_->push_button_log_,
      ui_->push_button_ln_,
      ui_->push_button_sin_,
      ui_->push_button_cos_,
      ui_->push_button_tan_,
      ui_->push_button_asin_,
      ui_->push_button_acos_,
      ui_->push_button_atan_,
      ui_->push_button_pow_,
      ui_->push_button_square_root_,
      ui_->push_button_x_,
      ui_->push_button_e};
  for (auto button : kAllButtons) {
    buttons_->addButton(button);
  }
}

void View::ResizeMainWindow() {
  switch (width()) {
    case 310:
      setMaximumWidth(630);
      setMinimumWidth(630);
      resize(630, 400);
      break;
    case 630:
      setMaximumWidth(310);
      setMinimumWidth(310);
      resize(310, 400);
      break;
  }
}

bool View::IncorrectExpression() {
  QString result_show = ui_->result_show_->text();
  QChar ch = result_show.back();
  return !(ch.isDigit() || ch == 'x' || ch == ')');
}

void View::SuccessfulCalculate() {
  // Если выражение не введено, нет смысла проводить расчет
  if (calculation_->press_button_stack_.empty()) {
    return;
  }

  calculation_->Postprocessing();
  double x = s21::ParseStrToDouble(ui_->line_edit_x_);
  std::string expression = text_expression_.toStdString();
  double result = controller_->GetResult(expression, x);
  CleanTextExpression();
  if (std::isnan(result) || std::isinf(result)) {
    ui_->result_show_->setText(QString::number(result));
  } else {
    ResultNormalization(result);
    calculation_->LabelUpdate();
  }
}

void View::Calculate() {
  if (IncorrectExpression()) {
    ui_->error_label_->setText("Не корректное выражение!");
  } else {
    ui_->error_label_->setText("");
    SuccessfulCalculate();
  }
}

void View::ResultNormalization(double result) {
  std::string str = std::to_string(result);
  unsigned int pos_point = str.find('.');
  if (pos_point <= str.size()) {
    str.replace(pos_point, 1, ",");
  }
  size_t length = str.length();
  for (int i = 0; i < 6; ++i) {
    if (str.back() != '0') {
      break;
    }
    str.pop_back();
    length--;
  }

  // В случае если было удалено 6 нулей, удаляется и точка
  if (str.back() == ',') {
    str.pop_back();
    length--;
  }

  // Стек заполняется так, чтобы ответ можно было использовать для вычислений
  for (size_t i = 0; i < length; ++i) {
    calculation_->PushNew(QString(str[i]));
  }
}

void View::keyPressEvent(QKeyEvent* event) {
  QPushButton* button =
      GetButton(static_cast<Qt::Key>(event->key()), event->modifiers());
  if (button) {
    button->click();
  }
}

QPushButton* View::GetButton(Qt::Key key, Qt::KeyboardModifiers modifiers) {
  if (Qt::ShiftModifier & modifiers) {
    return KeyWithShift(key);
  } else {
    return KeyWithoutShift(key);
  }
}

QPushButton* View::KeyWithShift(Qt::Key key) {
  static const QMap<Qt::Key, QPushButton*> kKeyButtons{
      {Qt::Key_Percent, ui_->push_button_mod_},
      {Qt::Key_Asterisk, ui_->push_button_mul_},
      {Qt::Key_Slash, ui_->push_button_div_},
      {Qt::Key_Plus, ui_->push_button_plus_},
      {Qt::Key_AsciiCircum, ui_->push_button_pow_},
      {Qt::Key_Comma, ui_->push_button_point_},
      {Qt::Key_Period, ui_->push_button_point_},
      {Qt::Key_ParenLeft, ui_->push_button_left_parenthesis_},
      {Qt::Key_ParenRight, ui_->push_button_right_parenthesis_},
      {Qt::Key_Backspace, ui_->push_button_clear_},
      {Qt::Key_S, ui_->push_button_asin_},
      {Qt::Key_C, ui_->push_button_acos_},
      {Qt::Key_T, ui_->push_button_atan_}};

  return kKeyButtons.contains(key) ? kKeyButtons.value(key) : nullptr;
}

QPushButton* View::KeyWithoutShift(Qt::Key key) {
  static const QMap<Qt::Key, QPushButton*> kKeyButtons{
      {Qt::Key_E, ui_->push_button_e},
      {Qt::Key_0, ui_->push_button_num_0_},
      {Qt::Key_1, ui_->push_button_num_1_},
      {Qt::Key_2, ui_->push_button_num_2_},
      {Qt::Key_3, ui_->push_button_num_3_},
      {Qt::Key_4, ui_->push_button_num_4_},
      {Qt::Key_5, ui_->push_button_num_5_},
      {Qt::Key_6, ui_->push_button_num_6_},
      {Qt::Key_7, ui_->push_button_num_7_},
      {Qt::Key_8, ui_->push_button_num_8_},
      {Qt::Key_9, ui_->push_button_num_9_},
      {Qt::Key_Comma, ui_->push_button_point_},
      {Qt::Key_Period, ui_->push_button_point_},
      {Qt::Key_Plus, ui_->push_button_plus_},
      {Qt::Key_Minus, ui_->push_button_minus_},
      {Qt::Key_Asterisk, ui_->push_button_mul_},
      {Qt::Key_Slash, ui_->push_button_div_},
      {Qt::Key_L, ui_->push_button_log_},
      {Qt::Key_N, ui_->push_button_ln_},
      {Qt::Key_S, ui_->push_button_sin_},
      {Qt::Key_C, ui_->push_button_cos_},
      {Qt::Key_T, ui_->push_button_tan_},
      {Qt::Key_R, ui_->push_button_square_root_},
      {Qt::Key_X, ui_->push_button_x_},
      {Qt::Key_Backspace, ui_->push_button_backspace_},
      {Qt::Key_Equal, ui_->push_button_equal_},
      {Qt::Key_Return, ui_->push_button_equal_},
      {Qt::Key_Enter, ui_->push_button_equal_},
      {Qt::Key_Delete, ui_->push_button_clear_}};

  return kKeyButtons.contains(key) ? kKeyButtons.value(key) : nullptr;
}

void View::SetValidator() {
  const QRegularExpression kRegExp("^-?(0[.,]\\d*|[1-9]\\d*[.,]?\\d*)$");
  QRegularExpressionValidator* validator =
      new QRegularExpressionValidator(kRegExp, this);

  ui_->line_edit_x_->setValidator(validator);
  ui_->line_edit_max_x_->setValidator(validator);
  ui_->line_edit_min_x_->setValidator(validator);
  ui_->line_edit_max_y_->setValidator(validator);
  ui_->line_edit_min_y_->setValidator(validator);
}

void View::StartSetting() {
  ResizeMainWindow();
  SetValidator();
  ui_->error_label_graph_->hide();
}

bool View::IsGraphRangeValid() const {
  double max_x = ParseStrToDouble(ui_->line_edit_max_x_);
  double min_x = ParseStrToDouble(ui_->line_edit_min_x_);
  double max_y = ParseStrToDouble(ui_->line_edit_max_y_);
  double min_y = ParseStrToDouble(ui_->line_edit_min_y_);
  return (max_x > min_x) && (max_y > min_y);
}

}  // end namespace s21
