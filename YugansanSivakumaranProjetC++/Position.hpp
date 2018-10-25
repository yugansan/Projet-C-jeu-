/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Position.hpp
 * Author: yugan
 *
 * Created on 31 décembre 2017, 17:00
 */

#ifndef POSITION_HPP
#define POSITION_HPP

class Position{
  private:
    int posX;
    int posY;
  public:
    Position(int posX, int posY);
    ~Position();
    int getPositionX();
    int getPositionY();
};

#endif /* POSITION_HPP */

