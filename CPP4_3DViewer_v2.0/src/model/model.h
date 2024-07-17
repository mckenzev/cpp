#ifndef VIEWER_V_2_0_SRC_MODEL_MODEL_H
#define VIEWER_V_2_0_SRC_MODEL_MODEL_H

#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "../utils.h"

namespace s21 {

using my_vector = std::vector<double>&;
using my_string = const std::string&;

class Model {
 public:
  Model(std::vector<double>& coordinates, std::vector<double>& vertices,
        std::string& filename_)
      : coordinates_(coordinates),
        vertices_(vertices),
        filename_(filename_),
        vertices_count_(0),
        faces_count_(0) {}

  /**
   * @brief Открывает и считывает файл, а так же заполняет массив coords_,
   * который используется для отрисовки обьекта.
   * @param filename Название файла.
   * @param coords Ссылка на массив.
   * @return True - открытие и считывание файла прошли успешно.
   * False - возникли ошибки, файла не существует и прочие проблемы.
   */
  bool Parse();

  /**
   * @brief Масштабирование объекта.
   * @param value Коэффициент масштабирования.
   */
  void Scale(double value);

  /**
   * @brief Перемещение объекта вдоль оси вдоль оси
   * @param value значение перемещения
   * @param axis ось перемещения ('x', 'y' или 'z')
   */
  void Move(const double& step, const Axis& axis);

  /**
   * @brief Вращение объекта вокруг оси.
   * @param step угол вращенияю
   * @param axis ось вращения ('x', 'y' или 'z')
   */
  void Rotate(const double& step, const Axis& axis);

  /**
   * @brief Заполняет вектор coords.
   */
  void FillingCoords();

  /**
   * @brief Нормализация координат обьекта // !!! Написать более точный
   * комментарий
   */
  void Normalization();

 private:
  /**
   * @brief Структура для хранения максимальных и минимальных значений по осям.
   */
  struct MinMax {
    double x_min = 0.0;
    double x_max = 0.0;
    double y_min = 0.0;
    double y_max = 0.0;
    double z_min = 0.0;
    double z_max = 0.0;
  };

  /**
   * @brief Очищает вектора если это возможно.
   */
  void CleanVectors();

  /**
   * @brief Через reserve для всех векторов резервирует необходимый для них
   * обьем памяти. Помогает от realloc`ов, который могут возникнуть если
   * capacity окажется меньше поступающих данных.
   */
  void MemoryAllocation();

  /**
   * @brief Считает количество vertex и faces в файле
   */
  bool CountingLines();  // aka variableCount

  /**
   * @brief Считает количество полигонов (Face).
   * @param line Строка из файла, в которой есть инфа о полигоне.
   */
  void CountingFaces(my_string line);

  /**
   * @brief Независимый от локали парсинг из string в числовой тип.
   * @param str Строка для распарса.
   */
  template <typename T>
  T ParseStrTo(my_string str);

  /**
   * @brief Считывает данные из файла, заполняет vertices_ и vectors_.
   * @return True - метод отработал успешно. False - возникли ошибки.
   */
  bool ReadingData();  // aka getValue

  /**
   * @brief Заполняет вектор vertices.
   * @param line Строка с данными о вершинах.
   */
  void VerticesProcessing(my_string line);

  /**
   * @brief Заполняет вектор faces.
   * @param line Строка с данными о индексах вершин.
   */
  void FacesProcessing(my_string line);

  /**
   * @brief Вспомогательный метод для заполнения faces_
   * @param line Строка с индексами "f ..."
   */
  void PushIndex(my_string line);

  /**
   * @brief Находит самые отдаленные точки по осям, для корректной отрисовки
   * объекта.
   */
  void GetMinMax();

  /**
   * @brief Находит максимальное расстояние между точками на осях. (x_min -
   * x_min и т.д.).
   * @return Максимальное растояние между точками по трем осям.
   */
  double MaxDifference();

  /**
   * @brief На основе min_max_ устанавливает обьек в центр проекции.
   */
  void Centralization();

  void DetermineModifier(const Axis& axis, size_t& first_modifier,
                         size_t& second_modifier);

  /**
   * @brief Упорядоченный массив с координатами для передачи во View.
   * Формат [x1, y1, z1 ... xn, yn, zn].
   */
  std::vector<double>& coordinates_;

  /**
   * @brief Массив с координатами (в файле "v ").
   * Формат [x1, y1, z1 ... xn, yn, zn].
   */
  std::vector<double>& vertices_;
  std::string& filename_;  /// << Название файла.

  /**
   * @brief Индексы вершин для формирования полигона (в файле "f ").
   */
  std::vector<int> faces_;
  MinMax min_max_;  /// < Минимальные и максимальные значения по осям.
  size_t vertices_count_;  /// < Количество вершин.
  size_t faces_count_;     /// < Количество граней.
};

}  // namespace s21

#endif  // VIEWER_V_2_0_SRC_MODEL_MODEL_H
