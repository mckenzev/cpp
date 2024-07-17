#ifndef VIEWER_V_2_0_SRC_VIEW_H
#define VIEWER_V_2_0_SRC_VIEW_H

#include <QApplication>
#include <QColorDialog>
#include <QFileDialog>
#include <QImage>
#include <QMainWindow>
#include <QMessageBox>
#include <QSettings>
#include <QTextEdit>
#include <QTimer>
#include <QtCore>

#include "../controller/controller.h"
#include "../model/model.h"
#include "../utils.h"
#include "qtgifimage/src/gifimage/qgifimage.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class View;
}
QT_END_NAMESPACE
namespace s21 {
class View : public QMainWindow {
  Q_OBJECT
 public:
  View(QWidget* parent = nullptr);
  ~View();
  void saveSetts();
  void loadSetts();
  QColor bk, bl, wh;
  QString last_obj;

 private slots:
  void interface(bool a);
  void loadChecker();
  bool on_loadModelFileButton_clicked();
  int loadMod(QString filename);
  void moveRepeat();
  void on_changeBGColorButton_clicked();
  void on_checkBox_ln_clicked(bool checked);
  void on_checkBox_pn_clicked(bool checked);
  void on_pnSizeSpinBox_valueChanged(double arg1);
  void on_radio_sphere_clicked(bool checked);
  void on_radio_cube_clicked(bool checked);
  void on_checkBox_ln_2_clicked(bool checked);
  void on_lnWidthSpinBox_valueChanged(double arg1);
  void on_radioButton_4_clicked();
  void on_radioButton_5_clicked();
  void on_edgesColorButton_clicked();
  void on_verticesColorButton_clicked();
  void on_moveRightButton_clicked();
  void on_moveLeftButton_clicked();
  void on_moveDownButton_clicked();
  void on_moveUpButton_clicked();
  void on_moveBackwardButton_clicked();
  void on_moveForwardButton_clicked();
  void on_rotateDownButton_clicked();
  void on_rotateUpButton_clicked();
  void on_rotateLeftButton_clicked();
  void on_rotateRightButton_clicked();
  void on_rotateClockwiseButton_clicked();
  void on_rotateCounterclockwiseButton_clicked();
  void on_doubleSpinBox_valueChanged(double arg1);
  void on_screencastButton_clicked();
  void on_screenshotButton_clicked();
  void makeRotate(const double& step, const s21::Axis& axis);
  void makeMove(const double& step, const s21::Axis& axis);
  void GifRecord();

 private:
  void SaveGif();

  Ui::View* ui;
  std::string filename_;
  std::vector<double> coordinates_;
  std::vector<double> vertices_;
  Controller controller_;
  QTimer* timer_;
  double gif_time_;
  QVector<QImage> imgQVector;
};
}  // namespace s21
#endif  // VIEWER_V_2_0_SRC_VIEW_H
