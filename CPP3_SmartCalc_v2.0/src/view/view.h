#ifndef SMART_CALC_SRC_VIEW_H_
#define SMART_CALC_SRC_VIEW_H_

#include <QButtonGroup>
#include <QKeyEvent>
#include <QMainWindow>
#include <QPushButton>
#include <QWidget>

#include "../controller/controller.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class View;
}
QT_END_NAMESPACE

namespace s21 {
class View : public QMainWindow {
  Q_OBJECT

 public:
  /**
   * @brief Конструктор класса View.
   * @param parent Родительский виджет.
   * @param controller Указатель на контроллер.
   */
  explicit View(QWidget* parent = nullptr, Controller* controller = nullptr);

  /**
   * @brief Деструктор класса View.
   */
  ~View();

  class Calculation;
  class Graph;

 private slots:
  /**
   * @brief Изменяет размер окна при переключении на вкладку с графиком.
   */
  void ResizeMainWindow();

  /**
   * @brief Обрабатывает нажатие кнопки и обновляет текст выражения.
   * @param id Идентификатор нажатой кнопки.
   */
  void PressButton(int id);

  /**
   * @brief Очищает текстовое поле выражения и стек введенных символов.
   */
  void CleanTextExpression();

  /**
   * @brief Удаляет последний введенный символ из выражения.
   */
  void PressBackspace();

  /**
   * @brief Отображает график функции на основе введенного выражения.
   */
  void ShowGraph();

  /**
   * @brief Выполняет расчет введенного выражения и отображает результат.
   */
  void Calculate();

 private:
  /**
   * @brief Создает группу кнопок для ввода выражений.
   */
  void CreateQButtonGroup();

  /**
   * @brief Устанавливает все необходимые соединения сигналов и слотов.
   */
  void AllConnects();

  /**
   * @brief Проверяет корректность введенного выражения.
   * @return true, если выражение некорректно, иначе false.
   */
  bool IncorrectExpression();

  /**
   * @brief Выполняет расчет выражения и отображает результат.
   */
  void SuccessfulCalculate();

  /**
   * @brief Нормализует результат вычисления и обновляет отображение.
   * @param result Результат вычисления.
   */
  void ResultNormalization(double result);

  /**
   * @brief Обрабатывает нажатие клавиш на клавиатуре.
   * @param event Событие нажатия клавиши.
   */
  void keyPressEvent(QKeyEvent* event) override;

  /**
   * @brief Возвращает кнопку, соответствующую нажатой клавише.
   * @param key Код клавиши.
   * @param modifiers Модификаторы клавиши.
   * @return Указатель на соответствующую кнопку.
   */
  QPushButton* GetButton(Qt::Key key, Qt::KeyboardModifiers modifiers);

  /**
   * @brief Возвращает кнопку, соответствующую нажатой клавише с Shift.
   * @param key Код клавиши.
   * @return Указатель на соответствующую кнопку.
   */
  QPushButton* KeyWithShift(Qt::Key key);

  /**
   * @brief Возвращает кнопку, соответствующую нажатой клавише без Shift.
   * @param key Код клавиши.
   * @return Указатель на соответствующую кнопку.
   */
  QPushButton* KeyWithoutShift(Qt::Key key);

  /**
   * @brief Устанавливает валидатор для полей ввода, ограничивая ввод только
   * чисел.
   */
  void SetValidator();

  /**
   * @brief Выполняет начальные настройки окна.
   */
  void StartSetting();

  /**
   * @brief Проверяет корректность диапазонов графика.
   * @return true, если диапазоны корректны, иначе false.
   */
  bool IsGraphRangeValid() const;

  // Переменные-члены класса
  Ui::View* ui_;  ///< Указатель на пользовательский интерфейс.
  Controller* controller_;  ///< Указатель на контроллер.
  Calculation* calculation_;  ///< Указатель на объект Calculation.
  Graph* graph_;              ///< Указатель на объект Graph.
  QString text_expression_;  ///< Текущий текст выражения.
  QButtonGroup* buttons_;  ///< Группа кнопок для ввода выражений.
};
}  // namespace s21
#endif  // SMART_CALC_SRC_VIEW_H_
