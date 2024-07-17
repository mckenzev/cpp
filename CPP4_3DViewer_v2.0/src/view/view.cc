#include "view.h"

#include "ui_view.h"

namespace s21 {

View::View(QWidget* parent)
    : QMainWindow(parent),
      bk(Qt::black),
      bl(Qt::blue),
      wh(Qt::white),
      ui(new Ui::View),
      controller_(coordinates_, vertices_, filename_),
      timer_(new QTimer(0)),
      gif_time_(0) {
  ui->setupUi(this);
  ui->widget->backColor = Qt::gray;
  ui->widget->vertices_ = &this->vertices_;
  ui->widget->coordinates_ = &this->coordinates_;
  loadSetts();
  loadChecker();
  connect(timer_, SIGNAL(timeout()), this, SLOT(GifRecord()));
  ui->label->setWordWrap(true);
  if (last_obj == "") {
    on_loadModelFileButton_clicked();
  } else {
    loadMod(last_obj);
  }
}

View::~View() {
  saveSetts();
  delete timer_;
  delete ui;
}

void View::interface(bool a) { ui->tabWidget->setEnabled(a); }

void View::loadChecker() {
  ui->pnSizeSpinBox->setValue(ui->widget->point_sz);
  ui->lnWidthSpinBox->setValue(ui->widget->line_sz);
  if (!ui->widget->projection) {
    ui->radioButton_4->setChecked(1);
  } else {
    ui->radioButton_5->setChecked(1);
  }
  if (!ui->widget->point_type) {
    ui->radio_cube->setChecked(1);
  } else {
    ui->radio_sphere->setChecked(1);
  }
  if (ui->widget->dashed) {
    ui->checkBox_ln_2->setChecked(1);
  } else {
    ui->checkBox_ln_2->setChecked(0);
  }
  if (ui->widget->points) {
    ui->checkBox_pn->setChecked(1);
  } else {
    ui->checkBox_ln->setChecked(0);
  }
  if (ui->widget->lines) {
    ui->checkBox_ln->setChecked(1);
  } else {
    ui->checkBox_ln->setChecked(0);
  }
}

bool View::on_loadModelFileButton_clicked() {
  bool res = false;
  QString filename = QFileDialog::getOpenFileName(
      this, "choose file", QCoreApplication::applicationDirPath(),
      "Text Files (*.obj)");
  if (filename == "") {
    res = true;
  } else {
    filename_ = filename.toStdString();
    loadMod(filename);
  }
  return res;
}

int View::loadMod(QString filename) {
  size_t res = controller_.Parse();
  if (res) {
    interface(true);
    last_obj = filename;
    ui->label->setText(filename);
    ui->vectors->setText("Vectors: " +
                         QString::number(coordinates_.size() / 6));
    ui->vertex->setText("Vertices: " + QString::number(vertices_.size() / 3));
  } else {
    ui->label->setText("ERROR. Please try another file");
    on_loadModelFileButton_clicked();
  }
  ui->widget->update();
  return res;
}

void View::on_changeBGColorButton_clicked() {
  QColor qcolor = QColorDialog::getColor(Qt::blue, this);
  ui->widget->backColor = qcolor;
  ui->widget->update();
}

void View::on_checkBox_ln_clicked(bool checked) {
  ui->widget->lines = checked;
  ui->widget->update();
}

void View::on_checkBox_pn_clicked(bool checked) {
  ui->widget->points = checked;
  ui->widget->update();
}

void View::on_pnSizeSpinBox_valueChanged(double arg1) {
  ui->widget->point_sz = arg1;
  ui->widget->update();
}

void View::on_radio_sphere_clicked(bool checked) {
  ui->widget->point_type = checked;
  ui->widget->update();
}

void View::on_radio_cube_clicked(bool checked) {
  ui->widget->point_type = !checked;
  ui->widget->update();
}

void View::on_checkBox_ln_2_clicked(bool checked) {
  ui->widget->dashed = checked;
  ui->widget->update();
}

void View::on_lnWidthSpinBox_valueChanged(double arg1) {
  ui->widget->line_sz = arg1;
  ui->widget->update();
}

void View::on_radioButton_4_clicked() {
  ui->widget->projection = 0;
  ui->widget->update();
}

void View::on_radioButton_5_clicked() {
  ui->widget->projection = 1;
  ui->widget->update();
}

void View::moveRepeat() {
  controller_.FillingCoords();
  ui->widget->update();
}

void View::on_edgesColorButton_clicked() {
  QColor qcolor = QColorDialog::getColor(Qt::blue, this);
  ui->widget->lineColor = qcolor;
  ui->widget->update();
}

void View::on_verticesColorButton_clicked() {
  QColor qcolor = QColorDialog::getColor(Qt::blue, this);
  ui->widget->pointColor = qcolor;
  ui->widget->update();
}

void View::makeMove(const double& step, const s21::Axis& axis) {
  controller_.Move(step, axis);
  moveRepeat();
}

void View::on_moveRightButton_clicked() { makeMove(-kStep, s21::X); }

void View::on_moveLeftButton_clicked() { makeMove(kStep, s21::X); }

void View::on_moveDownButton_clicked() { makeMove(-kStep, s21::Y); }

void View::on_moveUpButton_clicked() { makeMove(kStep, s21::Y); }

void View::on_moveBackwardButton_clicked() { makeMove(-kStep, s21::Z); }

void View::on_moveForwardButton_clicked() { makeMove(kStep, s21::Z); }

void View::makeRotate(const double& step, const s21::Axis& axis) {
  controller_.Rotate(step, axis);
  moveRepeat();
}

void View::on_rotateDownButton_clicked() { makeRotate(kStep, s21::X); }

void View::on_rotateUpButton_clicked() { makeRotate(-kStep, s21::X); }

void View::on_rotateLeftButton_clicked() { makeRotate(kStep, s21::Y); }

void View::on_rotateRightButton_clicked() { makeRotate(-kStep, s21::Y); }

void View::on_rotateClockwiseButton_clicked() { makeRotate(-kStep, s21::Z); }

void View::on_rotateCounterclockwiseButton_clicked() {
  makeRotate(kStep, s21::Z);
}

void View::on_doubleSpinBox_valueChanged(double argument) {
  controller_.Normalization();
  controller_.Scale(argument);
  moveRepeat();
}

void View::saveSetts() {
  QSettings settings(
      QCoreApplication::applicationDirPath() + "/3d_settings.conf",
      QSettings::NativeFormat);
  settings.setValue("Colors/bg", ui->widget->backColor.name(QColor::HexArgb));
  settings.setValue("Colors/ln", ui->widget->lineColor.name(QColor::HexArgb));
  settings.setValue("Colors/pn", ui->widget->pointColor.name(QColor::HexArgb));
  settings.setValue("Size/point", ui->widget->point_sz);
  settings.setValue("Size/line", ui->widget->line_sz);
  settings.setValue("Proj/proj", ui->widget->projection);
  settings.setValue("Types/pn", ui->widget->point_type);
  settings.setValue("Types/ln", ui->widget->dashed);
  settings.setValue("Exist/pn", ui->widget->points);
  settings.setValue("Exist/ln", ui->widget->lines);
  settings.setValue("Last_file", last_obj);
}

void View::loadSetts() {
  QSettings settings(
      QCoreApplication::applicationDirPath() + "/3d_settings.conf",
      QSettings::NativeFormat);
  ui->widget->backColor = settings.value("Colors/bg", wh).toString();
  ui->widget->lineColor = settings.value("Colors/ln", bk).toString();
  ui->widget->pointColor = settings.value("Colors/pn", bl).toString();
  ui->widget->line_sz = settings.value("Size/line", 1).toInt();
  ui->widget->point_sz = settings.value("Size/point", 1).toInt();
  ui->widget->projection = settings.value("Proj/proj", 1).toInt();
  ui->widget->point_type = settings.value("Types/pn", 0).toInt();
  ui->widget->dashed = settings.value("Types/ln", 0).toInt();
  ui->widget->points = settings.value("Exist/pn", 0).toInt();
  ui->widget->lines = settings.value("Exist/ln", 1).toInt();
  last_obj = settings.value("Last_file", "").toString();
}

void View::on_screencastButton_clicked() { timer_->start(100); }

void View::GifRecord() {
  if (gif_time_ < 4.9) {
    imgQVector.push_back(ui->widget->grabFramebuffer());
    gif_time_ += 0.1;
    ui->gif_timer_label->setText(QString::number(gif_time_, 'f', 2));
  } else {
    SaveGif();
    timer_->stop();
  }
}

void View::SaveGif() {
  QFileDialog dialog(this);
  QString path =
      QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
  QString gifQString =
      dialog.getSaveFileName(this, "Save gif as...", path, "GIF (*.gif);;");
  QGifImage gif;
  gif.setDefaultTransparentColor(Qt::black);
  gif.setDefaultDelay(100);
  for (auto img : imgQVector) {
    QImage img_scaled = img.scaled(640, 480);
    gif.addFrame(img_scaled);
  }
  gif.save(gifQString);
  imgQVector.clear();
  gif_time_ = 0;
  ui->gif_timer_label->setText("");
}

void View::on_screenshotButton_clicked() {
  QImage img(ui->widget->size(), QImage::Format_RGB32);
  QPainter painter(&img);
  QString tmp = QCoreApplication::applicationDirPath();
  tmp.resize(tmp.size() - 38);
  QString fileName =
      QFileDialog::getSaveFileName(this, tr("Save file"), tmp + "~/images.jpg",
                                   tr("JPG (*.jpg);; BMP (*.bmp)"));
  ui->widget->render(&painter);
  if (img.save(fileName)) {
    QMessageBox msgBox;
    msgBox.setText("Screenshot has been saved");
    msgBox.exec();
  } else {
    QMessageBox::warning(this, "", "Save failed.");
  }
}

}  // namespace s21
