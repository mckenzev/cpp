#include <QApplication>

#include "controller/controller.h"
#include "model/model.h"
#include "view/view.h"

int main(int argc, char *argv[]) {
  QApplication application(argc, argv);
  s21::Model model;
  s21::Controller controller(&model);
  s21::View view(nullptr, &controller);
  view.show();
  return application.exec();
}
