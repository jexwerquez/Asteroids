#include "../includes/asteroids.h"

void Asteroids::draw_asteroid(int color) {
  for (long unsigned int i = 0; i < asteroid.size(); i++) {
    for (long unsigned int j = 0; j < asteroid[i].size(); j++) {
      mvaddch(position.getY() + i, position.getX() + j,
              asteroid[i][j] | COLOR_PAIR(color));
    }
  }
}
void Asteroids::erase_asteroid() {
  for (long unsigned int i = 0; i < asteroid.size(); i++) {
    for (long unsigned int j = 0; j < asteroid[i].size(); j++)
      mvaddch(position.getY() + i, position.getX() + j, ' ');
  }
}
void Asteroids::move_ast(int offset) {
  position.setX(position.getX() - offset);
}

void drawAsts(Asteroids* ast, int color) { ast->draw_asteroid(color); }
void eraseAsts(Asteroids* ast) { ast->erase_asteroid(); }
void moveAstsLeft(Asteroids_Manager* ast_manage, Asteroids* aster, int a) {
  if (aster->getPos().getX() < (ast_manage->getField()).getFieldWidth() &&
      aster->getPos().getX() > 1 && aster->getPos().getY() >= -5 &&
      aster->getPos().getY() < (ast_manage->getField()).getFieldHeight())
    aster->move_ast(1);
  else
    ast_manage->destruct_asteroid(a);
}

void Asteroids_Manager::asts_manage(int health) {
  for (long unsigned int i = 0; i < asters.size(); i++) eraseAsts(asters[i]);
  for (long unsigned int i = 0; i < asters.size(); i++) moveAstsLeft(this, asters[i], i);
  vector<vector<char>> asteroid = {
      {'*', ' '},
      {'*', '*'},
  };
  Space_Object ast_pos(
      field.getFieldWidth() - 2,
      1 + rand() % (field.getFieldHeight() - asteroid.size() - 1));
  asters.push_back(new Asteroids(asteroid, ast_pos, 1 + rand() % health));
  for (long unsigned int i = 0; i < asters.size(); i++) {
    drawAsts(asters[i], asters.at(i)->getHealt());
  }
}

void Asteroids_Manager::destruct_asteroid(int i) {
  delete asters.at(i);
  asters.erase(asters.begin() + i);
}
