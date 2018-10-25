/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Item.hpp
 * Author: yugan
 *
 * Created on 3 janvier 2018, 00:13
 */

#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>
#include <stdlib.h>     /* srand, rand */

#include "Position.hpp"


class Item{
private:
    char representation;
    std::string description;
    int effet;
    Position *position;
public:
    Item(char represention,std::string description,int effet,Position *position);
    Item();
    Item(Item &item);
    char getRepresentation()const;
    int getEffet() const;
    void setEffet(int e);
    std::string getDescription()const;
    int utiliserItem()const;
    Position *getPosition()const;
    virtual bool mettreDansBesace() const;
};

class Potion :public  Item{
public:
    Potion(char represention, Position *position);
    Potion(Item &item);
};

class Bombe : public Item{
public:
    Bombe(char represention, Position *position);
    Bombe(Item &item);
};

class Bouclier :public  Item{
public:
    Bouclier(char represention, Position *position);
    Bouclier(Item &item);
    bool mettreDansBesace() const;
};

#endif /* ITEM_HPP */
