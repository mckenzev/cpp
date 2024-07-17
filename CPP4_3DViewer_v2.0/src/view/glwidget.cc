#include "glwidget.h"

#include "ui_view.h"

namespace s21 {

GLWidget::GLWidget(QWidget *parent)
    : QOpenGLWidget(parent),
      lines(true),
      points(true),
      point_type(false),
      projection(true),
      dashed(false),
      point_sz(1),
      line_sz(1),
      x_rot_(0),
      y_rot_(0) {}

void GLWidget::initializeGL() {
  initializeOpenGLFunctions();
  glEnable(GL_DEPTH_TEST);
}

void GLWidget::resizeGL(int w, int h) { glViewport(0, 0, w, h); }

void GLWidget::SetProjection(bool projection) {
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  if (projection) {
    glFrustum(-0.5, 0.5, -0.5, 0.5, 1, 9999999);
  } else {
    glOrtho(-1, 1, -1, 1, 1, 9999999);
  }
}

void GLWidget::paintGL() {
  SetProjection(projection);
  glClearColor(backColor.redF(), backColor.greenF(), backColor.blueF(),
               backColor.alphaF());
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glTranslated(0, 0, -2);  //-scale);
  glRotatef(x_rot_, 1, 0, 0);
  glRotatef(y_rot_, 0, 1, 0);
  if (points) {
    DrawPoints();
  }
  if (lines) {
    DrawLines();
  }
}

void GLWidget::DrawPoints() {
  glPointSize(point_sz);
  glColor3d(pointColor.redF(), pointColor.greenF(), pointColor.blueF());
  glVertexPointer(3, GL_DOUBLE, 0, vertices_->data());  ///
  glEnableClientState(GL_VERTEX_ARRAY);
  if (point_type) {
    glEnable(GL_POINT_SMOOTH);
  } else {
    glDisable(GL_POINT_SMOOTH);
  }
  glDrawArrays(GL_POINTS, 0, vertices_->size() / 3);  ///
  glDisableClientState(GL_VERTEX_ARRAY);
}

void GLWidget::DrawLines() {
  glLineWidth(line_sz);
  glColor3d(lineColor.redF(), lineColor.greenF(),
            lineColor.blueF());  // цвет линий
  glVertexPointer(3, GL_DOUBLE, 0, coordinates_->data());
  glEnableClientState(GL_VERTEX_ARRAY);
  if (dashed) {
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(3, 0xAAA);
  } else {
    glDisable(GL_LINE_STIPPLE);
  }
  glDrawArrays(GL_LINES, 0, coordinates_->size() / 3);
  glDisableClientState(GL_VERTEX_ARRAY);
}

void GLWidget::mousePressEvent(QMouseEvent *mo) { m_pos_ = mo->pos(); }

void GLWidget::mouseMoveEvent(QMouseEvent *mo) {
  x_rot_ = 1 / M_PI * (mo->pos().y() - m_pos_.y());
  y_rot_ = 1 / M_PI * (mo->pos().x() - m_pos_.x());
  update();
}
}  // namespace s21
