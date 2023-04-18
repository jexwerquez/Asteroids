#ifndef ZONE
#define ZONE
#include "base.h"
#include "objects.h"
#include "rules.h"
#include "spaceship.h"
/** @brief Массив коэффициентов зон
 * @param fuzzy_coef[0] очень большой коэффициент (0.9 - 1.0)
 * @param fuzzy_coef[1] большой коэффициент (0.7 - 0.9)
 * @param fuzzy_coef[2] средний коэффициент (0.5 - 0.7)
 * @param fuzzy_coef[3] маленький коэффициент (0.3 - 0.5)
 * @param fuzzy_coef[4] очень маленький коэффициент (0.0 - 0.3)
 **/
extern float fuzzy_coef[5];
/** @brief Массив расстояний зон
 * @param fuzzy_dist[0] очень большое расстояние (более 5 зон по Х и У)
 * @param fuzzy_dist[1] большое расстояние (4 - 5 зон по Х и У)
 * @param fuzzy_dist[2] среднее расстоние (3 - 4 зоны по Х и У)
 * @param fuzzy_dist[3] маленькое расстояние (2 - 3 зоны по Х и У)
 * @param fuzzy_dist[4] очень маленькое расстояние (до 2х зон по Х и У)
 **/
extern int fuzzy_dist[5];

/** @brief Массив расстояний зон
 * @param fuzzy_prio[0] очень большой приоритет (100 - 125)
 * @param fuzzy_prio[1] большой приоритет (75 - 100)
 * @param fuzzy_prio[2] средний приоритет (50 - 75)
 * @param fuzzy_prio[3] маленький приоритет (25 - 50)
 * @param fuzzy_prio[4] очень маленький приоритет (0 - 25)
 **/
extern int fuzzy_prio[5];

/**
 * @brief Класс зон поля
 * @param height высота зоны
 * @param width ширина зону
 * @param coefficient весовой коэффициент зоны: чем ближе к 1, тем он
 *оптимальнее
 **/
class Zone : public Space_Object {
  int height;
  int width;
  float coefficient;
  int priority;

protected:
  Space_Object position;

public:
  Zone(int h, int w, float coef, int p, Space_Object pos)
      : height(h), width(w), coefficient(coef), priority(p), position(pos){};
  /** @brief получение высоты зоны */
  int getHeight() { return height; }
  /** @brief получение ширины зоны */
  int getWidth() { return width; }
  /** @brief получение коэффициента зоны */
  float getCoefficient() { return coefficient; }
  /** @brief получение приоритета зоны */
  int getPriority() { return priority; }
  /** @brief установка коэффициента зоны */
  void setCoefficient(float c) { coefficient = c; }
  /** @brief установка приоритета зоны */
  void setPriority(int p) { priority = p; }
  /** @brief получение расстояния от Spaceship до зоны по оси X
   * @return возвращает значение > 0, если зона находится левее от
   * местоположения Spaceship и < 0, если правее
   */
  int getDistanceX(Spaceship *, Zone *);
  /** @brief получение расстояния от Spaceship до зоны по оси Y
   * @return возвращает значение > 0, если зона находится выше от местоположения
   * Spaceship и < 0, если ниже
   */
  int getDistanceY(Spaceship *, Zone *);
  /** @brief получение позиции зоны на поле */
  Space_Object getPos() { return position; };
  /** @brief проверка есть ли объект внутри зоны */
  bool inside_the_zone(Space_Object);
  /** @brief установка приоритета зоны по входным данным*/
  void priority_processing(Spaceship *, Zone *);
  /** @brief вычисление отклонения от зоны в терминах НР*/
  int rejection(int, Field *, char);
};
#endif