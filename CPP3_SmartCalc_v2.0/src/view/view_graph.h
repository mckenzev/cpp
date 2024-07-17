#ifndef SMART_CALC_SRC_VIEW_GRAPH_H_
#define SMART_CALC_SRC_VIEW_GRAPH_H_

#include <QGraphicsView>

#include "view.h"

namespace s21 {

class View::Graph {
 public:
  /**
   * @brief Конструктор класса Graph.
   * @param parent Указатель на родительский объект View.
   */
  explicit Graph(View* parent);

  /**
   * @brief Деструктор класса Graph.
   */
  ~Graph();

  /**
   * @brief Передает матрицу с точками для графика.
   * @param matrix Указатель на вектор с координатами точек.
   */
  void PassMatrix(std::vector<int>& matrix);

  /**
   * @brief Инициализирует графическое представление.
   */
  void Initialization();

  /**
   * @brief Показывает график.
   */
  void Show();

  /**
   * @brief Возвращает параметры графика.
   * @return Константная ссылка на параметры графика.
   */
  const GraphParams& GetParams() const;

 private:
  /**
   * @brief Устанавливает середину координатной системы.
   */
  void SetMiddle();

  /**
   * @brief Устанавливает шаги по осям X и Y.
   */
  void SetSteps();

  /**
   * @brief Инициализирует неизменяемые значения.
   */
  void InitImmutableValues();

  /**
   * @brief Инициализирует изменяемые значения.
   */
  void InitValues();

  /**
   * @brief Инициализирует коэффициент масштабирования.
   */
  void InitScaleFactor();

  /**
   * @brief Инициализирует настройки графика.
   */
  void InitSetting();

  /**
   * @brief Инициализирует оси графика.
   */
  void InitAxis();

  /**
   * @brief Рисует ось X.
   * @param axis Объект QPen для настройки рисования оси.
   */
  void DrawAxisX(const QPen& axis);

  /**
   * @brief Рисует шаги по оси X.
   * @param axis Объект QPen для настройки рисования шагов.
   */
  void DrawStepsX(const QPen& axis);

  /**
   * @brief Рисует ось Y.
   * @param axis Объект QPen для настройки рисования оси.
   */
  void DrawAxisY(const QPen& axis);

  /**
   * @brief Рисует шаги по оси Y.
   * @param axis Объект QPen для настройки рисования шагов.
   */
  void DrawStepsY(const QPen& axis);

  /**
   * @brief Проверяет, является ли точка нормальной.
   * @param y Координата точки по оси Y.
   * @return true, если точка находится в пределах допустимых значений, иначе
   * false.
   */
  bool IsNormalPoint(qreal y);

  /**
   * @brief Отображает график.
   */
  void PrintGraph();

  /**
   * @brief Очищает вектор.
   * @tparam T Тип вектора.
   * @param vec Вектор для очистки.
   */
  template <typename T>
  void ClearVector(T& vec);

  View* parent_view_;  ///< Указатель на родительский вид.
  bool initialized_;  ///< Флаг инициализации.
  QGraphicsView* graphics_view_;  ///< Указатель на графическое представление.
  s21::GraphParams params_;  ///< Параметры графика.
  qreal x_step_;             ///< Шаг по оси X.
  qreal y_step_;             ///< Шаг по оси Y.
  qint64 x_middle_;          ///< Середина по оси X.
  qint64 y_middle_;          ///< Середина по оси Y.
  QVector<qreal> matrix_;  ///< Матрица точек для графика.
  QGraphicsScene* scene_;  ///< Графическая сцена.
};

}  // namespace s21

#endif  // SMART_CALC_SRC_VIEW_GRAPH_H_
