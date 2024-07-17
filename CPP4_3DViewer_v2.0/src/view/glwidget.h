#ifndef VIEWER_V_2_0_SRC_VIEW_GLWIDGET_H
#define VIEWER_V_2_0_SRC_VIEW_GLWIDGET_H

#include <QColor>
#include <QOpenGLFunctions>
#include <QOpenGLWidget>
#include <QtGui>
#include <QtOpenGL>
#include <vector>

namespace s21 {

class GLWidget : public QOpenGLFunctions, public QOpenGLWidget {
 public:
  GLWidget();
  explicit GLWidget(QWidget *parent = 0);
  void initializeGL() override;
  void resizeGL(int w, int h) override;
  void paintGL() override;
  void DrawLines();
  void DrawPoints();
  void Change();
  void SetProjection(bool projection);

  std::vector<double> *vertices_;
  std::vector<double> *coordinates_;
  QColor backColor, lineColor, pointColor;
  bool lines, points, point_type, projection, dashed;
  int point_sz = 1, line_sz = 1;

 private:
  void mousePressEvent(QMouseEvent *) override;
  void mouseMoveEvent(QMouseEvent *) override;
  float x_rot_, y_rot_;

  QPoint m_pos_;
};

}  // namespace s21
#endif  // VIEWER_V_2_0_SRC_VIEW_GLWIDGET_H
