#ifndef SPACESHIP
#define SPACESHIP
#include "base.h"
#include "field.h"
#include "objects.h"
class Spaceship : public Space_Object {
  int health;
  char spaceship;
  int heel;

protected:
  Space_Object position;

public:
  Spaceship(int h, char ssp, int he, Space_Object pos)
      : health(h), spaceship(ssp), heel(he), position(pos){};
  void draw_spaceship(int);
  void erase_spaceship();
  int getHealt() { return health; };
  void setHeath(int h) { health = h; };
  char getSprite() { return spaceship; };
  void moveHorizontal(int);
  void moveVertical(int);
  int getHeel() { return heel; };
  void setHeel(int h) { heel = h; };
  Space_Object change_position(int, Field);
  Space_Object getPos() { return position; };
};
#endif
