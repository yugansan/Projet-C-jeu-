#include "Position.hpp"

Position::Position(int posX, int posY):posX(posX),posY(posY){}

Position::~Position(){}

int Position::getPositionX(){
  return Position::posX;
}

int Position::getPositionY(){
  return Position::posY;
}